//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-22
//  FILENAME    : HW03B002.CPP
//  DESCRIPTION : Find all prime numbers within 1000
//================================================================

// the boundry of integers we are instrested in
#define MAX 1000

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
    // np[i] == false iff number i is prime
    bool np[MAX + 1];
    for (int i = 0; i < MAX; i++) { np[i] = false; }

    // starting from 2, remove 2*2, 2*3, ... from list
    for (int i = 2; i < MAX; i++) {
        // skip numbers that are already removed
        if (np[i]) continue;
        for (int j = 2 * i; j < MAX; j += i) {
            np[j] = true;
        }
    }

    cout << "PRIME TABLE: " << endl;
    for (int i = 2, cnt = 0; i < MAX; i++) {
        if (!np[i]) {
            cout << setw(5) << i << " ";
            cnt++;
            if (cnt % 12 == 0) {
                cout << endl;
            }
        }
    }

    cout << endl;

    cout << "TWIN PRIMES:" << endl;
    for (int i = 4, cnt = 0; i < MAX; i++) {
        if (!np[i] && !np[i-2]) {
            cout << "("
                 << setw(3) << (i - 2)
                 << ", "
                 << setw(3) << i
                 << ")  ";
            cnt++;
            if (cnt % 6 == 0) {
                cout << endl;
            }
        }
    }

    cout << endl;

    system("pause");
}

