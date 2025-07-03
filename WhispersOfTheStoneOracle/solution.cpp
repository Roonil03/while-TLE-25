#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result = {""};  // Start with an empty combination

        for (char digit : digits) {
            vector<string> temp;
            string letters = mapping[digit - '0'];

            for (string prefix : result) {
                for (char letter : letters) {
                    temp.push_back(prefix + letter);
                }
            }

            result = temp;  // Move to next digit's combinations
        }

        return result;
    }
};

int main() {
    string input;
    cout << "Enter the Oracle's digit message (2-9): ";
    cin >> input;

    Solution sol;
    vector<string> combinations = sol.letterCombinations(input);

    cout << "Possible interpretations:\n";
    for (const string& combo : combinations) {
        cout << combo << " ";
    }
    cout << endl;

    return 0;
}
