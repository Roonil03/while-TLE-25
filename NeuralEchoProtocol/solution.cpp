#include "bits-stdc++.h"
using namespace std;
using bigInt = __int128;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        ll A, N, M;
        cin >> A >> N >> M;
        solve(A, N, M);
    }
    return 0;
}
