// Convert a string into JAV-whatever-the-fuck-I-forgot code.
// For each letter in the given string, if it's a vowel and its next letter is not the same, add "av" in front of it, otherwise skip it.
// For example: "hello, secret meeting tonight." => "havellavo, savecravet maveetaving tavonavight."

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    string text = "hello, secret meeting tonight.";
    string result = "";
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < 5; j++)
            if (text[i] == vowel[j] && text[i - 1] != text[i])
                result += "av";
        result.push_back(text[i]);
    }
    cout << result << endl;
    return 0;
}