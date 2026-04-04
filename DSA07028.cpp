#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int& x:a) cin>>x;
        stack<int> st;

        vector<int> pge(n, -1);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[i] >= a[st.top()]) {
                st.pop();
            }
            if(!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            cout << i - (pge[i] + 1) + 1 << " ";
        }
        cout << "\n";
    }
}