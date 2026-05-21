#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        for(ll& x: a) cin >> x;
        vector<ll> dp(k+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j < n; j++) {
                if(a[j] <= i) {
                    dp[i] = (dp[i] + dp[i-a[j]]) % MOD;
                }
            }
        }
        // for (int j = 0; j < n; j++)
        //     for (int i = a[j]; i <= k; i++)
        //         dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        cout << dp[k] << "\n";
    }    
}