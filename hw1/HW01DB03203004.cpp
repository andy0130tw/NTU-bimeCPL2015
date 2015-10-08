//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-09-30
//  FILENAME    : HW01DB03203004.CPP
//  DESCRIPTION : This is a program to calculate the result of a mathematical formula
//================================================================

#include "stdafx.h"
#include<iostream>

using namespace std;

int main(int argc, _TCHAR* argv[])
{
	double F = 4.0;
	double k = 1e3;
	double l = 3000.0;
	double w = 40;
	double d = 2;

	double ep_Al = 68950;
	double ep_Cu = 11e4;

	double I_Al = F * k * l / (w * d * ep_Al);
	cout << "The increase in length of a slab of aluminum is: " << I_Al << endl;

	double I_Cu = F * k * l / (w * d * ep_Cu);
	cout << "The increase in length of a slab of copper   is: " << I_Cu << endl;

	cin.get();
	return 0;
}
