#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a, b;
int sum = 0;
vector<int> d;

vector<int> get_sign(int target, int n, vector<int>& d, int sum) {
    if (target < -sum || target > sum) return {};
    int k = target + sum;
    if (k % 2 != 0) return {};
    int need = k / 2;

    bitset<MAXSUM> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) dp |= (dp << d[i]);
    if (!dp[need]) return {};

    // Reconstruction: greedy từ cuối
    // Với mỗi item i từ n-1..0, check xem có lấy được không
    // bằng cách re-run DP trên tập con còn lại
    vector<int> sign(n, -1);
    int cur = need;
    
    // Precompute suffix DP
    vector<bitset<MAXSUM>> suf(n + 1);
    suf[n][0] = 1;
    for (int i = n-1; i >= 0; i--)
        suf[i] = suf[i+1] | (suf[i+1] << d[i]);

    for (int i = 0; i < n && cur > 0; i++) {
        // Nếu lấy item i: cần suffix[i+1] đạt cur - d[i]
        if (cur >= d[i] && suf[i+1][cur - d[i]]) {
            sign[i] = 1;
            cur -= d[i];
        }
        // Ngược lại: không lấy, tiếp tục
    }

    return (cur == 0) ? sign : vector<int>{};
}

int main() {
    cin >> n >> a >> b;
    d.resize(n);
    for(int& x:d) {
        cin >> x;
        sum += x;
    }

    int target_u = a + b;
    int target_v = a - b;
    
    vector<int> sign_u = get_sign(target_u);
    vector<int> sign_v = get_sign(target_v);

    if(sign_u.empty() || sign_v.empty()) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    for(int i = 0; i < n; i++) {
        if(sign_u[i] == 1 && sign_v[i] == 1) {
            cout << "R";
        } else if(sign_u[i] == 1 && sign_v[i] == -1) {
            cout << "U";
        } else if(sign_u[i] == -1 && sign_v[i] == 1) {
            cout << "D";
        } else {
            cout << "L";
        }
    }

    return 0;
}