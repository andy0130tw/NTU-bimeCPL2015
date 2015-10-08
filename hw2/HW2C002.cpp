//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-10-08
//  FILENAME    : HW02C002.CPP
//  DESCRIPTION : This is a program to calculate BMR and express it in numbers of chocolate bars.
//================================================================

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
  double weight, height, age;
  char gender;

  cout << "Enter your weight (in kg): ";
  cin >> weight;

  cout << "Enter your height (in cm): ";
  cin >> height;

  cout << "Enter your age (in year): ";
  cin >> age;

  // M for male and F for female
  cout << "Enter your gender (M / F): ";
  cin >> gender;

  double bmr;

  // accepts both uppercase and lowercase
  if (gender == 'M' || gender == 'm')
    bmr = 66.5 + 13.75 * weight + 5.003 * height - 6.755 * age;
  else if (gender == 'F' || gender == 'f')
    bmr = 655 + 9.563 * weight + 1.850 * height - 4.676 * age;
  else {
    // input invalid
    cout << "Please enter either M or F for your gender! Exiting..." << endl;
    return 0;
  }

  cout << "You need to eat " 
       << bmr / 230 
       << " chocolate bar(s) at least to maintain your life."
       << endl;

  system("pause");
  return 0;
}

