#include <bits/stdc++.h>

using namespace std;

int m;
vector<int> adj[100005];
bool visited[100005];

bool dfs(int u, int s) {
    visited[u] = true;
    if(u == s) return true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(dfs(v, s)) return true;
        }
    }
    return false;
}

int main() {
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        if(z == 1) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        } else {
            memset(visited, false, sizeof(visited));
            cout << dfs(x, y) << "\n";
        }
    }

}