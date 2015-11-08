//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-30
//  FILENAME    : HW04C002.CPP
//  DESCRIPTION : Sort a list of pairs of numbers on either field.
//================================================================


// #include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdlib>

using namespace std;

void swap2(int a[2], int b[2]) {
    int i = a[0], j    = a[1];
     a[0] = b[0]; a[1] = b[1];
     b[0] = i;    b[1] = j;
}

// sorton is the i-th field we want to sort on
// sortorder is 0 if desc otherwise asc.
void sortDesc(int data[][2], int len, int sorton = 1, int sortorder = 0) {
    // bubble sort; inefficient but it's enough here
    int k = 0;
    bool ok = false;
    for (int i = 0; i < len; i++) {
        if (ok) break;
        ok = true;
        for (int j = i; j < len; j++) {
            if (
              (!sortorder && data[i][sorton] < data[j][sorton]) ||
              (sortorder  && data[i][sorton] > data[j][sorton])
            ) {
                ok = false;
                swap2(data[i], data[j]);
            }
        }
    }
}

int main() {
    // maximum item is 100
    int a[100][2];
    int n = 0;
    
    cout << "Enter some data in stock: (100 items at most)" << endl;
    cout << "Syntax: [<PartNo.> <Quantity>], enter \"0 0\" to end the input." << endl;
        
    while(n < 100) {
        cout << "#" << setw(3) << right << (n+1) << ": ";
        int i, j;
        cin >> i >> j;
        if (i == 0 && j == 0)
            break;
        else { a[n][0] = i; a[n][1] = j; }
        n++;
    }
    
    sortDesc(a, n);
    
    cout << endl;
    cout << "Sorted by quantity desc.: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(8) << left  << a[i][0] 
             << setw(8) << right << a[i][1] << endl;
    }

    sortDesc(a, n, 0, 1);
    cout << "Sorted by product no. asc.: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(8) << left  << a[i][0] 
             << setw(8) << right << a[i][1] << endl;
    }
    
}

