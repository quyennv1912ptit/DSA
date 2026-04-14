#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        vector<int> adj[1005];
        int parent[1005];
        for(int i = 1; i <= 1000; i++) {
            parent[i] = -1;
        }
        int n, m; cin >> n >> m;
        int u, v; cin >> u >> v;
        for(int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            // adj[b].push_back(a);
        }
        queue<int> q;
        q.push(u);
        parent[u] = 0;
        int found = false;

        while(!q.empty()) {
            int k = q.front();
            q.pop();

            if(k == v) {
                found = true;
                break;
            }

            for(int s : adj[k]) {
                if(parent[s] == -1) {
                    q.push(s);
                    parent[s] = k;
                }
            }
        }

        // for(int i = 1; i <= n; i++) {
        //     cout << parent[i] << " ";
        // }
        // cout << "\n";

        if(!found) cout << "-1\n";
        else {
        int k = v;
        vector<int> path;
        while(k != 0) {
            path.push_back(k);
            k = parent[k];
        }

        reverse(path.begin(), path.end());

        for(int x : path) {
            cout << x << " ";
        }

        cout << "\n";
        }


    }
}