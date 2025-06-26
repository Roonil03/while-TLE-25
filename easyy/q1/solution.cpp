#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) {
            if (a <= k)
                k++;
            else
                break;
        }
        return k;
    }
};

int main() {
    string line;
    vector<int> arr;
    int k;

    // Read array input
    cout << "Enter array elements (space-separated): ";
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    // Read k
    cout << "Enter k: ";
    cin >> k;

    // Solve
    Solution sol;
    int result = sol.findKthPositive(arr, k);

    // Output result
    cout << "Kth missing number is: " << result << endl;

    return 0;
}
