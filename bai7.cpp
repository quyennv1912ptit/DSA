#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;
vector<int> adj[MAX];
int disc[MAX], low[MAX], timer;
bool dinh_tru[MAX];
int canh_cau = 0;

void dfs(int u, int p = -1) {
    int children = 0;
    disc[u] = low[u] = ++timer;
    for(int v : adj[u]) {
        if(v == p) continue;
        if(disc[v]) {
            low[u]=min(low[u], disc[v]);
        } else {
            children++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) {
                canh_cau++;
            }
            if(p!=-1 && low[v] >= disc[u]) {
                dinh_tru[u] = true;
            }
        }
    }
    if(p == -1 && children > 1) {
        dinh_tru[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer = 0;
    for(int i = 1; i <= n; i++) {
        if(!disc[i]) dfs(i);
    }

    int tru = 0;
    for(int i = 1; i <= n; i++) {
        if(dinh_tru[i]) tru++;
    }
    cout << tru << " " << canh_cau << "\n";
}