#include <fstream>
#include "../testlib.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMerged(const string& x, const string& y, const string& z) {
    if (x.size() + y.size() != z.size()) return false;
    int m = x.size(), n = y.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else {
                if (i > 0 && x[i - 1] == z[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j > 0 && y[j - 1] == z[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

string randomString(int len) {
    string s;
    for (int i = 0; i < len; i++)
        s += (char)rnd.next('a', 'z');
    return s;
}

string mergeShuffle(const string& x, const string& y) {
    string merged;
    int i = 0, j = 0;
    while (i < x.size() || j < y.size()) {
        if (i < x.size() && j < y.size()) {
            if (rnd.next(0, 1)) merged += x[i++];
            else merged += y[j++];
        } else if (i < x.size()) merged += x[i++];
        else merged += y[j++];
    }
    return merged;
}

void writeTest(int fileNum) {
    string num = (fileNum < 10 ? "0" : "") + to_string(fileNum);
    ofstream input("SignalInput" + num + ".txt");
    ofstream output("SignalOutput" + num + ".txt");

    int T = rnd.next(1, 100);
    input << T << '\n';

    for (int t = 0; t < T; ++t) {
        int len1 = rnd.next(0, 100);
        int len2 = rnd.next(0, 100);
        string x = randomString(len1);
        string y = randomString(len2);

        string z;
        bool valid = rnd.next(0, 1);
        if (valid) {
            z = mergeShuffle(x, y);
        } else {
            int len3 = len1 + len2;
            z = randomString(len3);
            while (isMerged(x, y, z)) {
                z = randomString(len3);
            }
        }

        input << x << '\n' << y << '\n' << z << '\n';
        output << (isMerged(x, y, z) ? "true" : "false") << '\n';
    }

    input.close();
    output.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 0; i < 4; ++i)
        writeTest(i);
    return 0;
}
