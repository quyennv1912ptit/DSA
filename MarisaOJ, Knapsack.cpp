#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, T; cin >> n >> T;
    vector<int> cnt(T+1, 0);
    for(int i = 0; i < n; i++) {
        int w; cin >> w;
        if(w <= T) {
            cnt[w]++;
        }
    }
    bitset<1000005> dp;
    dp[0] = 1;
    for(int w = 1; w <= T; w++) {
        int c = cnt[w];
        int p = 1;
        while(c > 0) {
            int t = min(c, p);
            int total_w = w * t;
            dp |= (dp << total_w);
            c -= t;
            p *= 2;
        }
    }
    for(int i = 1; i <= T; i++) cout << dp[i];
}