// Create the decimal zip of two non-negative intergers A and B

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int Solution(int A, int B)
{
    // Convert to given number to string
    string strNumA = to_string(A);
    string strNumB = to_string(B);
    string strResult = "";

    // Generate result string
    int i = 0;
    while (i < strNumA.size() || i < strNumB.size()) {
        if (i < strNumA.size())
            strResult += strNumA[i];
        if (i < strNumB.size())
            strResult += strNumB[i];
        i++;
    }

    // Convert the result string back into number
    unsigned long int nResult = stoll(strResult);

    // Return -1 if result exceeds 100,000,000
    if (nResult > 100000000)
        return -1;

    // Otherwise return the result
    return nResult;
}

int main()
{
	int nNumberA, nNumberB;

    // If the user enters invalid numbers, keep asking them to re-enter
    // until the received inputs are non-negative
	do {
		cout << "Enter first number: "; cin >> nNumberA;
	} while (nNumberA < 0); 
	do {
		cout << "Enter second number: "; cin >> nNumberB;
	} while (nNumberB < 0);

    // Call the function to generate the decimal zip of the two given numbers and print the result
    int nDecimalZip = Solution(nNumberA, nNumberB);
    if (nDecimalZip == -1)
        cout << "Result out of range" << endl;
    else
        cout << "The decimal zip of A and B is " << nDecimalZip << endl;

    system("pause");
	return 0;
}