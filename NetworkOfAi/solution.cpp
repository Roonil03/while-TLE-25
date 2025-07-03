#include "bits-stdc++.h"
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> color;
ll global_ans;

map<int, int> dfs(int u, int parent) {
    int c0 = color[u];
    map<int, int> f;
    ll total_c0 = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;
        map<int, int> g = dfs(v, u);
        if (c0) {
            auto it = g.find(c0);
            if (it != g.end()) {
                total_c0 += it->second;
                g.erase(it);
            }
        }
        if (f.size() < g.size()) swap(f, g);
        for (auto &[col, cnt] : g) {
            if (f.count(col)) {
                global_ans += (ll) f[col] * (ll) cnt;
            }
            f[col] += cnt;
        }
    }

    if (c0) {
        global_ans += total_c0;
        f[c0] = 1;
    }

    return f;
}

void solve() {
    int n;
    cin >> n;
    color.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    global_ans = 0;
    dfs(1, -1);
    cout << global_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
