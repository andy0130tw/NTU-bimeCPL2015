//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-11-08
//  FILENAME    : HW04D002.CPP
//  DESCRIPTION : A 2-dice simulator.
//================================================================

#ifdef _MSC_VER
#include "stdafx.h"
#endif // _MSC_VER

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

void printPercentage(ostream& os, double num) {
    os << (num * 100) << "%";
}

int dice() { return rand() % 6 + 1; } 
int toss() { return dice() + dice(); }

void showToss(int cnt) {
    int result[13] = {0};
    double ther_prob_base = 1.0 / 36;
    
    for (int i = 0; i < cnt; i++) {
        result[toss()]++;
    }
 
    cout << "Tossing for " << cnt << " times..." << endl;
    
    // set precision for all the floats we are going to output
    cout << setprecision(3) << fixed;
    
    for (int i = 2; i <= 12; i++) {
        double exp_prob = ((double)result[i] / cnt);
        double ther_prob = ther_prob_base * min(i-1, 13-i);
        
        cout << setw(2) << right << i
             << ": " 
             << setw(6) << right << result[i];
             
        cout << " "
             << setw(6);
        // experimental probability
        printPercentage(cout, exp_prob);
        
        cout << " ("
             << setw(6);
        // theorical probility
        printPercentage(cout, ther_prob);
         
        cout << ", "
             << setw(6) << showpos;
        // difference
        printPercentage(cout, ther_prob - exp_prob);
        
        cout << noshowpos
             << ")"
             << endl;
    }
    
    cout << endl;
}

#ifdef _MSC_VER
int main(int argc, _TCHAR* argv[]) {
#else
int main() {
#endif // _MSC_VER

    // randomize; using time as random seed
    srand(time(NULL));
    
    showToss(1000);
    showToss(10000);
    showToss(100000);
    
    system("pause");
}

