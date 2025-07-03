#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
using ll = long long;

vector<pair<int,int>> pruferDecode(const vector<int>& code) {
    int n = code.size() + 2;
    vector<int> deg(n, 1);
    for (int x : code) deg[x]++;
    set<int> leaves;
    for (int i = 0; i < n; i++) 
        if (deg[i] == 1) leaves.insert(i);
    vector<pair<int,int>> edges;
    for (int x : code) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        edges.emplace_back(leaf, x);
        if (--deg[leaf] == 0) leaves.erase(leaf);
        if (--deg[x] == 1) leaves.insert(x);
    }
    int u = *leaves.begin();
    leaves.erase(leaves.begin());
    int v = *leaves.begin();
    edges.emplace_back(u, v);
    return edges;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(argc, argv);
    for (int fileId = 0; fileId < 4; fileId++) {
        string inName = "input";
        inName += (fileId < 10 ? "0" : "");
        inName += to_string(fileId);
        inName += ".txt";
        
        string outName = "output";
        outName += (fileId < 10 ? "0" : "");
        outName += to_string(fileId);
        outName += ".txt";
        
        ofstream fin(inName.c_str()), fout(outName.c_str());
        
        int t = rnd.next(1, 50);
        fin << t << "\n";
        ll sumN = 0;
        unordered_map<ll, int> freq;
        
        for (int ti = 0; ti < t; ti++) {
            int n;
            vector<pair<int, int>> edges;
            vector<int> cols;
            ll answer;
            bool valid = false;
            
            do {
                int remaining = t - ti;
                int maxN = min(20, int(400000 - sumN - 2LL * remaining));
                if (maxN < 2) maxN = 2;
                n = rnd.next(2, maxN);
                vector<int> code;
                if (n > 2) {
                    code.resize(n - 2);
                    for (int i = 0; i < n - 2; i++)
                        code[i] = rnd.next(0, n - 1);
                }
                edges = pruferDecode(code);
                cols.resize(n);
                for (int i = 0; i < n; i++)
                    cols[i] = rnd.next(1, n);
                
                vector<vector<int>> adj(n);
                for (auto &e : edges) {
                    int u = e.first, v = e.second;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                
                vector<int> parent(n, -1);
                vector<vector<int>> children(n);
                queue<int> q;
                q.push(0);
                parent[0] = -1;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : adj[u]) {
                        if (v == parent[u]) continue;
                        parent[v] = u;
                        children[u].push_back(v);
                        q.push(v);
                    }
                }
                
                vector<int> order;
                q.push(0);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    order.push_back(u);
                    for (int v : children[u])
                        q.push(v);
                }
                reverse(order.begin(), order.end());
                
                vector<map<int, int>> dp(n);
                ll global_ans = 0;
                
                for (int u : order) {
                    ll tot = 0;
                    vector<map<int, int>> childMaps;
                    for (int v : children[u]) {
                        if (dp[v].count(cols[u])) {
                            tot += dp[v][cols[u]];
                            dp[v].erase(cols[u]);
                        }
                        childMaps.push_back(move(dp[v]));
                    }
                    
                    map<int, int> mergedMap;
                    for (auto &g : childMaps) {
                        if (mergedMap.size() < g.size())
                            swap(mergedMap, g);
                        for (auto &pr : g) {
                            if (mergedMap.count(pr.first))
                                global_ans += (ll)mergedMap[pr.first] * pr.second;
                            mergedMap[pr.first] += pr.second;
                        }
                    }
                    dp[u] = move(mergedMap);
                    dp[u][cols[u]] = 1;
                    global_ans += tot;
                }
                
                answer = global_ans;
                if (freq.find(answer) == freq.end() || freq[answer] < 200) {
                    freq[answer]++;
                    sumN += n;
                    valid = true;
                } else {
                    sumN -= n;
                }
            } while (!valid);
            
            fin << n << "\n";
            for (int i = 0; i < n; i++) {
                fin << cols[i];
                if (i < n - 1) fin << ' ';
                else fin << '\n';
            }
            for (auto &e : edges) {
                fin << e.first + 1 << ' ' << e.second + 1 << '\n';
            }
            fout << answer << "\n";
        }
    }
    return 0;
}
