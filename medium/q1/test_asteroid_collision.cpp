#include <fstream>
#include "../testlib.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> parkingLotClash(const vector<int>& cars) {
    stack<int> stk;
    for (int car : cars) {
        bool destroyed = false;
        while (!stk.empty() && stk.top() > 0 && car < 0) {
            if (stk.top() < -car) {
                stk.pop();
                continue;
            } else if (stk.top() == -car) {
                stk.pop();
            }
            destroyed = true;
            break;
        }
        if (!destroyed) stk.push(car);
    }
    vector<int> result(stk.size());
    for (int i = stk.size() - 1; i >= 0; --i) {
        result[i] = stk.top(); stk.pop();
    }
    return result;
}

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    fstream test("InputDriftRacinngClash" + num + ".txt", ios::app);
    fstream answer("OutputDriftRachingClash" + num + ".txt", ios::app);

    int t = rnd.next(1, 100); // Corrected: t ≤ 100
    test << t << endl;

    while (t--) {
        int n = rnd.next(2, 10000); // n between 2 and 10^4
        test << n << endl;

        vector<int> cars(n);
        for (int i = 0; i < n; i++) {
            int size = rnd.next(1, 1000);      // size between 1 and 1000
            int dir = rnd.next(0, 1) ? 1 : -1;  // direction either +1 or -1
            cars[i] = dir * size;
            test << cars[i] << " ";
        }
        test << endl;

        vector<int> result = parkingLotClash(cars);
        for (int val : result) {
            answer << val << " ";
        }
        answer << endl;
    }

    test.close();
    answer.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}
