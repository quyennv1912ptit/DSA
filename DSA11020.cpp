#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a1(n);
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin >> a1[i];
            s.insert(a1[i]);
        }

        vector<int> a2;
        for(int x : s) a2.push_back(x);

        cout << (a1 == a2) << "\n";

    }
}