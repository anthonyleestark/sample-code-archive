#pragma once
// Skip if included
#ifndef NUMBERS_LAMBDA_INCLUDED
#define NUMBERS_LAMBDA_INCLUDED
// Include another neccessary library for processing numbers
#include <iostream>
#include <cmath>

// Count the digits of number
auto CountDigits = [](auto number)
{
	unsigned int count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
};

// Get the digit of a specific position of a number
auto GetDigitOfPos = [](auto number, auto position)
{
	int digit = (number / (int)pow(10, (double)CountDigits(number) - position)) % 10;
	return digit;
};

// Reverse an integer number
auto ReverseNumber = [](auto number)
{
	auto nAfterReverse = 0;
	while (number > 0)
	{
		nAfterReverse = nAfterReverse * 10 + (number % 10);
		number = number / 10;
	}
	return nAfterReverse;
};

// Check if a number is prime or not
auto IsPrime = [](auto number)
{
	for (int run = 2; run <= sqrt((double)number); run++)
		if (number % run == 0)
			return false;
	return true;
};

#endif
