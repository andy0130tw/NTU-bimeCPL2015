//================================================================
//  PROGRAMMER  : 潘廣霖 
//  DATE        : 2015-10-08
//  FILENAME    : HW02D002.CPP
//  DESCRIPTION : This is a program to help calculate the sum of 3 cards in a blackjack game
//================================================================

// not to rely on the max function in std::algorithm
#define min(a, b) ((a) < (b) ? (a) : (b))

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main(int argc, _TCHAR* argv[]) {
  int a, b, c, sum = 0;

  // 1 for A, 2 for 2, ..., K for 13
  cout << "Enter three cards in a blackjack game [1 ~ 13]: ";
  cin >> a >> b >> c;

  // treat 1 as one point
  int ace = (int)(a == 1 || b == 1 || c == 1);

  // this statement is equivent to
  // if (a > 10) sum += 10; else sum += a;
  // ... for b and c
  sum += min(a, 10) + min(b, 10) + min(c, 10);
 
  // promote ace to 11 points if the result does not exceed 21.
  // there is no need to handle multiple aces(?),
  // because it will not satisfy the condition.
  if (sum <= 11 && ace) sum += 10;

  cout << "These cards yield " << sum << " point(s)." << endl;
  
  system("pause");
  return 0;
}

