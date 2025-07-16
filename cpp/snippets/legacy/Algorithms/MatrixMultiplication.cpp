#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Test function below
vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b, size_t n) {
  vector<vector<int>> result(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        result[i][j] = 0;
        for (int k = 0; k < n; k++)
            result[i][j] += a[i][k] * b[k][j];
    }
  return result;
}
// Test function above

int main() {
    for (int n = 0; n < 2; n++) {
        int size = rand() % 2 + 2;
        vector<vector<int>> a(size, vector<int>(size));
        vector<vector<int>> b(size, vector<int>(size));
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                a[i][j] = rand() % 20; b[i][j] = rand() % 20;
            }
            
        cout << "Matrix A: {";
        for (int i = 0; i < size; i++) {
            cout << "{";
            for (int j = 0; j < size; j++) {
                cout << a[i][j];
                if (j < size - 1) cout << ", ";
            }
            cout << "}";
            if (i < size - 1) cout << ", ";
        }
        cout << "}" << endl;
        
        cout << "Matrix B: {";
        for (int i = 0; i < size; i++) {
            cout << "{";
            for (int j = 0; j < size; j++) {
                cout << b[i][j];
                if (j < size - 1) cout << ", ";
            }
            cout << "}";
            if (i < size - 1) cout << ", ";
        }
        cout << "}" << endl;
        
        vector<vector<int>> result(size, vector<int>(size));
        result = matrix_multiplication(a, b, size);
        
        cout << "Result (A*B): {";
        for (int i = 0; i < size; i++) {
            cout << "{";
            for (int j = 0; j < size; j++) {
                cout << result[i][j];
                if (j < size - 1) cout << ", ";
            }
            cout << "}";
            if (i < size - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
    return 0;
}