#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;

    for(int i = 0; i < 6; i++) {
        char c; cin >> c;
        a += c;
    }

    for(int i = 0; i < 6; i++) {
        char c; cin >> c;
        b += c;
    }

    if(a==b) {
        cout << 0 << "\n";
        return;
    }

    unordered_set<string> visited;

    queue<pair<string, int>> q;
    q.push({a, 0});
    
    visited.insert(a);

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        string t = p.first;
        int d = p.second;

        if(t == b) {
            cout << d << "\n";
            return;
        }

        string tmp1 = t;
        tmp1[0] = t[3];
        tmp1[1] = t[0];
        tmp1[4] = t[1];
        tmp1[3] = t[4];

        string tmp2 = t;
        tmp2[1] = t[4];
        tmp2[2] = t[1];
        tmp2[5] = t[2];
        tmp2[4] = t[5];

        if(visited.find(tmp1) == visited.end()) {
            q.push({tmp1, d+1});
            visited.insert(tmp1);
        }

        if(visited.find(tmp2) == visited.end()) {
            q.push({tmp2, d+1});
            visited.insert(tmp2);
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}