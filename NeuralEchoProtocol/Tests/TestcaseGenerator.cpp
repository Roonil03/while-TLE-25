#include "testlib.h"
#include "bits-stdc++.h"
#include <__msvc_int128.hpp>

using namespace std;
using bigInt = std::_Unsigned128;
using ll = long long;

ll modpow(ll a, ll e, ll m) {
    ll res = 1 % m;
    a %= m;
    while (e) {
        if (e & 1) res = (bigInt)res * a % m;
        a = (bigInt)a * a % m;
        e >>= 1;
    }
    return res;
}

pair<ll,ll> geo(ll b, ll n, ll M) {
    if (n == 0) return {0, 1 % M};
    if (n & 1) {
        auto p = geo(b, n - 1, M);
        ll s = (p.first + p.second) % M;
        ll pw = (bigInt)p.second * b % M;
        return {s, pw};
    } else {
        auto p = geo(b, n >> 1, M);
        ll s = (p.first + (bigInt)p.second * p.first % M) % M;
        ll pw = (bigInt)p.second * p.second % M;
        return {s, pw};
    }
}

void solve(ll A, ll N, ll M) {
    int k = to_string(A).size();
    ll base = modpow(10, k, M);
    auto p = geo(base, N, M);
    ll answer = (bigInt)(A % M) * p.first % M;
    cout << answer << "\n";
}

int main() {
    for (int fileIndex = 0; fileIndex < 10; fileIndex++) {
        rnd.setSeed(fileIndex);
        int T = rnd.next(1, 10);
        vector<tuple<ll,ll,ll>> tests;
        tests.reserve(T);
        for (int i = 0; i < T; i++) {
            ll A = rnd.next(0LL, 1000000000LL);
            int regime = rnd.next(1, 3);
            ll N;
            if (regime == 1) {
                N = rnd.next(1LL, 100LL);
            } else if (regime == 2) {
                N = rnd.next(101LL, 1000000LL);
            } else {
                N = rnd.wnext(1000001LL, 1000000000000LL, 2);
            }
            ll M = rnd.next(2LL, 1000000000LL);
            tests.emplace_back(A, N, M);
        }
        char inName[16], outName[16];
        sprintf(inName, "input%02d.txt", fileIndex);
        sprintf(outName, "output%02d.txt", fileIndex);
        ofstream inFile(inName);
        inFile << T << "\n";
        for (auto &t : tests) {
            inFile << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
        }
        inFile.close();
        ofstream outFile(outName);
        auto coutBuf = cout.rdbuf();
        cout.rdbuf(outFile.rdbuf());
        for (auto &t : tests) {
            solve(get<0>(t), get<1>(t), get<2>(t));
        }
        cout.rdbuf(coutBuf);
        outFile.close();
    }
    return 0;
}
