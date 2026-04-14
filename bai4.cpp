#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    bool found = false;
    for(int v = 1; v <= n; v++) {
        if(!visited[v]) {
            found = true;
            cout << v << "\n";
        }
    }
    if(!found) cout << "0\n";
}