#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

vector<int> dp(MAX, 0);

void precompute() {
    for(int i = 1; i < MAX; i++) {
        dp[i]=INT_MAX;
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    precompute();
    int t; cin >> t;
    while(t--) {
        solve();
    }
}