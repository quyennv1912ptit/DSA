#include <bits/stdc++.h>

using namespace std;

int parent[100001];
int sz[100001];

void make_set(int u) {
    parent[u] = u;
    sz[u] = 1;
}

int find_set(int v) {
    return parent[v] == v? v : parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a]+=sz[b];
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        make_set(i);
    }
    bool found = false;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if(find_set(a) == find_set(b)) {
            found = true;
        }
        union_sets(a, b);
    }
    cout << (found? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}