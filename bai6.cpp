#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;
vector<int> adj[MAX];
vector<int> rev_adj[MAX];
bool visited[MAX];
stack<int> st;

void dfs1(int u) {
    visited[u]=true;
    for(int v:adj[u]) {
        if(!visited[v]) dfs1(v);
    }
    st.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for(int v:rev_adj[u]) {
        if(!visited[v]) dfs2(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs1(i);
    }
    memset(visited, false, sizeof(visited));

    int scc = 0;
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!visited[u]) {
            scc++;
            dfs2(u);
        }
    }
    cout << scc << "\n";
}