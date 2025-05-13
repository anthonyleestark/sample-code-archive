#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string sum_strings(const string& a, const string& b) {
    string num1 = a, num2 = b, result = "";
    bool isSaveOne = false;
    string incr = "";
    for (long i = 0; i < abs(int(num1.length() - num2.length())); i++)
        incr.push_back('0');
    if (num1.length() > num2.length()) 
        num2 = incr + num2;
    else num1 = incr + num1;
    for (long i = num1.length() - 1; i >= 0; i--) {
        int sum = (num1[i] - '0') + (num2[i] - '0');
        if (isSaveOne) sum++;
        if (sum >= 10) { sum -= 10; isSaveOne = true; }
        else isSaveOne = false;
        result = to_string(sum) + result;
    }
    if (isSaveOne) result = "1" + result;
    return result;
}

string multiply_strings(const string& a, const string& b) {
    string num1 = a, num2 = b, result = "0";
    vector<string> products;
    if (num1.length() > num2.length()) {
        string temp = num1; num1 = num2; num2 = temp;
    }
    for (long i = num1.length() - 1; i >= 0; i--) {
        string product = "";
        bool isSaved = false;
        int savedNum = 0;
        for (long j = num2.length() - 1; j >= 0; j--) {
            int prod = (num1[i] - '0') * (num2[j] - '0');
            if (isSaved) prod += savedNum;
            if (prod >= 10) { savedNum = prod / 10; prod %= 10; isSaved = true; }
            else { isSaved = false; savedNum = 0; }
            product = to_string(prod) + product;
        }
        if (isSaved) product = to_string(savedNum) + product;
        products.push_back(product);
    }
    for (int i = products.size() - 1; i >= 0; i--) {
        string incr = "";
        for (int j = 1; j <= i; j++)
            incr.push_back('0');
        products[i] += incr;
        result = sum_strings(result, products[i]);
    }
    return result;
}

int main() {
    cout << "Enter test strings to test. Enter \"exit\" to quit." << endl;
    string num1, num2;
    do {
        cout << "Enter first number: "; getline(cin, num1);
        if (num1 == "exit") break;
        cout << "Enter second number: "; getline(cin, num2);
        if (num2 == "exit") break;
        cout << "The result of test function is: " << multiply_strings(num1, num2) << endl;
    } while (true);
    return 0;
}