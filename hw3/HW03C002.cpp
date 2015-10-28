//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-22
//  FILENAME    : HW03C002.CPP
//  DESCRIPTION : Simulate a traditional 12-key dialer
//================================================================

#include "stdafx.h"
#include<iostream>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
    string keys[10] = {"",
        " ",    "ABC", "DEF",
        "GHI",  "JKL", "MNO",
        "PQRS", "TUV", "WXYZ"
    };

    string output;
    int prev = 0, cnt = 0, c;
    char tok;
    while(cin >> tok) {
        c = tok - '0';
        if (!prev && !c) {
            break;
        } else if (prev == c) {
            cnt++;
        } else if (prev != 0) {
            output += keys[prev][cnt % keys[prev].length()];
            cnt = 0;
            prev = 0;
        }
        prev = c;
    }
    cout << output << endl;

    cin.get();
}

