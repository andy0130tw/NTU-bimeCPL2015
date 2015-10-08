//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-09-30
//  FILENAME    : HW01CB03203004.CPP 
//  DESCRIPTION : This is a program simulating p2.11 in textbook 
//================================================================

#include "stdafx.h"
#include<iostream>
using namespace std;

int main() {
	double speed, fe, fr;
	fe = 2e10;
	fr = 2.00000035e10;

	speed = 6.685e8 * (fr - fe) / (fr + fe);
	cout << "The speed is " << speed << " miles/hour " << endl;
	cin.get();
	return 0;
}
