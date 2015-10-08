//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-09-30
//  FILENAME    : HW01BB03203004.CPP 
//  DESCRIPTION : This is a program to compute the average of three integers 
//================================================================

#include "stdafx.h"
#include<iostream>
using namespace std;

int main() {
	double grade1;
	double grade2;
	double grade3;
	double total;
	double average;

	grade1 = 85.5;
	grade2 = 90.0;
	grade3 = 94.0;
	total = grade1 + grade2 + grade3;
	average = total / 3.0;

	cout << "(Given that grade3 = " << grade3 << ",) the average grade is " << average << endl;

	cin.get();
	return 0;
}