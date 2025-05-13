#pragma once
// Skip if included
#ifndef STDARRAY_INCLUDED
#define STDARRAY_INCLUDED
// Include another neccessary library for processing numbers
#include <iostream>

template <class arrayType>
template <class sizeType>

// Enter value for array
void EnterValue(arrayType arrayName[], sizeType size, const char* enter_label)
{
	arrayType temp_num = 0;
	for (int count = 0; count < size; count)
	{
		std::cin >> temp_num;
		arrayName[count] = temp_num;
	}
}

#endif
