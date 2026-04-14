#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005;
vector<int> adj[MAX];
int disc[MAX], low[MAX], timer;
int res[MAX];
int n, m;

void dfs(int u, int p, int cnt)
{
    disc[u] = low[u] = ++timer;
    int children = 0;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (disc[v])
        {
            low[u] = min(low[u], disc[v]);
        }
        else
        {
            dfs(v, u, cnt);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u])
            {
                children++;
            }
        }
    }
    if (p == -1)
    {
        res[u] = cnt - 1 + children;
    }
    else
    {
        res[u] = cnt + children;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(disc, 0, sizeof(disc));
    memset(res, 0, sizeof(res));
    for(int i = 1; i <= n; i++) {
         adj[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    timer = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            cnt++;
            dfs(i, -1, 0);
        }
    }

    timer = 0;
    memset(disc, 0, sizeof(disc));
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            dfs(i, -1, cnt);
        }
    }

    int* mx = max_element(res, res + MAX);

    if(*mx == 1) {
        cout << "0\n";
        return;
    }

    cout << (mx - res) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}