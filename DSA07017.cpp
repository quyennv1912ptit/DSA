#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int& x:a) cin>>x;
        vector<int> nge(n, n), nse(n, n);
        stack<int> st1, st2;

        for(int i = n-1; i >= 0; i--) {
            while(!st1.empty() && a[i] >= a[st1.top()]) {
                st1.pop();
            }
            if(!st1.empty()) {
                nge[i] = st1.top();
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

        for(int i = 0; i < n; i++) {
            int ng = nge[i];
            if(ng < n) {
                int ns = nse[ng];
                if(ns < n) {
                    cout << a[ns] << " ";
                } else {
                    cout << -1 << " ";
                }
            } else {
                cout << -1 << " ";
            }
        }

        cout << "\n";
    }
}