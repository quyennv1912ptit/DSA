#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int& x:a) cin>>x;
        stack<int> st1, st2;

        vector<int> pse(n, -1), nse(n, n);

        for(int i = 0; i < n; i++) {
            while(!st1.empty() && a[i] <= a[st1.top()]) {
                st1.pop();
            }

            if(!st1.empty()) {
                pse[i] = st1.top();
            }
            
            st1.push(i);
        }

        for(int i = n-1; i >= 0; i--) {
            while(!st2.empty() && a[i] <= a[st2.top()]) {
                st2.pop();
            }

            if(!st2.empty()) {
                nse[i] = st2.top();
            }
            
            st2.push(i);
        }

        ll mx = 0;

        for(int i = 0; i < n; i++) {
            mx = max(mx, 1LL * a[i] * (nse[i] - pse[i] - 1));
        }

        cout << mx << "\n";
    }
}