//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-10-08
//  FILENAME    : HW02B002.CPP
//  DESCRIPTION : This is a program to estimate the temperature of a fridge since a power failure
//================================================================

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
  int hh, mm;
  cout << "Enter time since power failure (<hour> <minute>): ";
  
  cin >> hh >> mm;
  double t = hh + mm / 60.0;
  // formula given in the question
  double ans =  4 * t * t / (t + 2) - 20;

  cout << endl << "Estimated T is " << ans << ". " << endl;
  system("pause");
  return 0;
}
