//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-22
//  FILENAME    : HW03D002.CPP
//  DESCRIPTION : GCD table of number 1 to 20
//================================================================

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

// my favorite GCD implementation
int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}


int main(int argc, _TCHAR* argv[]) {

    // table header
    cout << setw(6) << "";
    for (int i = 1; i <= 20; i++) {
        cout << setw(3) << right << i;
    }

    // horizonal line
    cout << endl
         << setw(68) << setfill('=') << ""
         << endl;
    cout << setfill(' ');

    // table body
    for (int i = 1; i <= 20; i++) {
        cout << setw(3) << right << i
             << " | ";
        for (int j = 1; j <= 20; j++) {
            cout << setw(3) << right << gcd(i, j);
        }
        cout << endl;
    }


    system("pause");
}

