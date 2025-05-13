#pragma once
// Skip if included
#ifndef NUMBERS_INT_INCLUDED
#define NUMBERS_INT_INCLUDED
// Include another neccessary library for processing numbers
#include <iostream>
#include <cmath>

// Count the digits of number
int CountDigits(int number)
{
	int count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

// Get the digit from the position in number
int DigitFromPos(int number, int position)
{
	int digit = (number / (int)pow(10, (double) CountDigits(number) - position)) % 10;
	return digit;
}

// Reverse an integer number
int ReverseNumber(int number)
{
	int nAfterReverse = 0;
	while (number > 0)
	{
		nAfterReverse = nAfterReverse * 10 + (number % 10);
		number = number / 10;
	}
	return nAfterReverse;
}

// Check if a number is prime or not
bool IsPrime(int number)
{
	for (int run = 2; run <= sqrt((double)number); run++)
		if (number % run == 0)
			return false;
	return true;
}

#endif
