#include <bits/stdc++.h>

using namespace std;

int in_[1001], lvl[1001], n;

void post_order(int lvl_idx, int in_start, int in_end) {
    int root = lvl[lvl_idx];

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> in_[i];
        for(int i = 0; i < n; i++) cin >> lvl[i];
        cout << "\n";
    }
}