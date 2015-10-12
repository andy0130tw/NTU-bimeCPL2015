//================================================================
//  PROGRAMMER  : 潘廣霖
//  DATE        : 2015-10-08
//  FILENAME    : HW02A002.CPP
//  DESCRIPTION : This is a program to print information about three integers
//================================================================

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstdlib>
// make use of the max/min function in std::algorithm
// ref: http://stackoverflow.com/q/19897722/2281355
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
using namespace std;

int main(int argc, _TCHAR* argv[]) {
  int a, b, c;
  cout << "Input three different integers: ";
  cin >> a >> b >> c;
  int sum = a + b + c;
  cout << "Sum is "             << sum           << endl;
  cout << "Average is "         << (sum / 3.0)   << endl;
  cout << "Product is "         << (a * b * c)   << endl;
  cout << "Smallest number is " << min3(a, b, c) << endl;
  cout << "Largest number is "  << max3(a, b, c) << endl;

  system("pause");
  return 0;
}
