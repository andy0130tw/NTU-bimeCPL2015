//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-29
//  FILENAME    : HW04A002.CPP
//  DESCRIPTION : Find all perfect number within 0..10000
//================================================================

// #include "stdafx.h"
#include<iostream>
#include<cstdlib>

using namespace std;

// return true if `Num` is a perfect number
bool PerfectNumber(long int Num) {
    int sum = 0;
    // compute all factors within sqrt(n)
    for (int i = 1; i*i <= Num; i++) {
        if (Num%i != 0) continue;
        sum += i;
        // if it is not a square number then add another factor
        if (i*i < Num) sum += Num/i;
    }
    // exclude the number itself
    sum -= Num;
    return (sum == Num);
}

int main() {
    cout << "Perfect numbers within 1 to 10000: " << endl;
    for (int i = 1; i < 10000; i++) {
        if (PerfectNumber(i))
          cout << i << endl;
    }
    system("pause");
}

