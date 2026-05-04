#include <bits/stdc++.h>

using namespace std;

int pre[1001], in_[1001], n;

void post_order(int pre_start, int in_start, int in_end) {

    if(in_start > in_end) return;

    int root = pre[pre_start];

    int idx = in_start;

    while(in_[idx] != root) idx++;

    int left_size = idx - in_start;

    post_order(pre_start + 1, in_start, idx-1);
    post_order(pre_start + 1 + left_size, idx+1, in_end);
    cout << root << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> in_[i];
        for(int i = 0; i < n; i++) cin >> pre[i];
        post_order(0, 0, n - 1);
        cout << "\n";
    }
}