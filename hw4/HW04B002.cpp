//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-29
//  FILENAME    : HW04B002.CPP
//  DESCRIPTION : Calculate avg and stdev of numbers, rejecting outlier using z test.
//================================================================

// #include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double __avg(double arr[], int cnt) {
    double sum = 0;
    for(int i = 0; i < cnt; i++)
        sum += arr[i];
    return sum / cnt;
}

double __stdev(double arr[], int cnt) {
    int sum2 = 0;
    for(int i = 0; i < cnt; i++) {
        sum2 += arr[i] * arr[i];
    }
    int avg = __avg(arr, cnt);
    return sqrt(sum2 / cnt - avg * avg);
}

void calculate(double arr[], int cnt, double& avg, double& stdev) {
    avg = __avg(arr, cnt);
    stdev = __stdev(arr, cnt);
} 

int main() {
    int n;
    cout << "Number of records [1~10]: n = ";
    cin >> n;
    
    if (n < 1 || n > 10) {
        cout << "Error! n should be within 1 to 10. Exiting...";
        system("pause");
        return 0;
    }
    
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    double avg;
    double stdev;
    
    calculate(arr, n, avg, stdev);
    
    double sub = avg - stdev * 2;
    double sup = avg + stdev * 2;
    
    cout << "Ori Average  = " << avg << endl;
    cout << "Ori St. Dev. = " << stdev << endl;
    cout << "95% CI   = [" << sub << ", " << sup << "]" << endl;
    
    double newarr[n];
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < sub || arr[i] > sup) {
            cout << "Rejecting " << arr[i] << " because it is away from (+/-)2 stdev.";
        } else {
            newarr[k++] = arr[i];
        }
    }

    calculate(newarr, k, avg, stdev);

    cout << "New Average  = " << avg << endl;
    cout << "New St. Dev. = " << stdev << endl;
    
    system("pause");
}

