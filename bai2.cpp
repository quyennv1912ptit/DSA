#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
int color[1005];

bool dfs(int u) {
    color[u] = 1;
    for(int v:adj[u]) {
        if(color[v] == 1) return true;
        if(color[v] == 0 && dfs(v)) return true;
    }
    color[u] = 2;
    return false;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(color, 0, sizeof(color));
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for(int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }
        bool found = false;
        for(int v = 1; v <= n; v++) {
            if(color[v]==0) {
                if(dfs(v)) {
                    found = true;
                    break;
                }
            }
        }
        cout << (found? "YES" : "NO") << "\n";
    }
}