#include <bits/stdc++.h>

using namespace std;

struct Trace {
    int i, j;
    char c;
    Trace() : i(0), j(0), c('\0') {}
    Trace(int ii, int jj, char cc = '\0'): i(ii), j(jj), c(cc) {}
};

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<Trace>> Tr(n + 1, vector<Trace>(m + 1));

    a = '_' + a;
    b = '_' + b;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int j = 1; j <= m; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                Tr[i][j] = Trace(i-1, j-1, a[i]);
            } else if(dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                Tr[i][j] = Trace(i-1, j);
            } else {
                dp[i][j] = dp[i][j-1];
                Tr[i][j] = Trace(i, j-1);
            }
        }
    }

    Trace t = Tr[n][m];
    string ans = "";

    while(1) {
        if(t.c != '\0') {
            ans = t.c + ans;
        }
        if(t.i == 0 || t.j == 0) {
            break;
        } else {
            t = Tr[t.i][t.j];
        }
    }

    cout << ans << "\n";
}