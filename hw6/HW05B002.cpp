//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-11-27
//  FILENAME    : HW05B002.CPP
//  DESCRIPTION : Compute a magic square of odd cells.
//================================================================

#include "stdafx.h"

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

#ifdef _MSC_VER
int _tmain(int argc, _TCHAR* argv[]) {
#else
int main() {
#endif // _MSC_VER
    int** magic;

    int n, n2;
    cout << "Input the edge N = ";
    cin >> n;
    n2 = n * n;

    if (!(n%2)) {
        cout << "n must be odd! exiting..." << endl;
        return 1;
    }

    // allocating an n x n matrix dynamically
    magic = new int* [n];
    for (int i = 0; i < n; i++) {
        magic[i] = new int[n];
        for (int j = 0; j < n; j++)
            magic[i][j] = 0;
    }

    // filling number
    int x = 0, y = n/2;
    for (int i = 0; i < n2; i++) {
        magic[x][y] = i+1;
        x = (x+n-1) % n;
        y = (y+1) % n;
        if (magic[x][y] > 0) {
            x = (x+2) % n;
            y = (y+n-1) % n;
        }
    }

    // printing
    cout << "Here is " << n << " x " << n << " magic square!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(5) << right << magic[i][j];
        cout << endl;
    }

    system("pause");
}

