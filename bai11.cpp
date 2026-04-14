#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 500005;
int n, m;
int h1, s1, h2, s2;
ll INF = LLONG_MAX;

vector<pair<int, ll>> adj[MAX];

void dijisktra(int start, vector<ll> &d_to)
{
    vector<ll> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto e : adj[u])
        {
            if (dist[u] + e.second < dist[e.first])
            {
                dist[e.first] = dist[u] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }

    d_to = dist;
}

void solve()
{
    cin >> n >> m;
    cin >> h1 >> s1 >> h2 >> s2;
    vector<tuple<int, int, ll>> es;

    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        es.push_back({a, b, c});
    }

    vector<ll> disth1, dists1, disth2, dists2;

    dijisktra(h1, disth1);
    dijisktra(s1, dists1);
    dijisktra(h2, disth2);
    dijisktra(s2, dists2);

    ll min_1 = disth1[s1];
    ll min_2 = disth2[s2];

    for (auto e : es)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        ll w = get<2>(e);

        if ((disth1[u] + w + dists1[v] == min_1 && disth2[u] + w + dists2[v] == min_2 && disth1[u] == disth2[u]) ||
            (disth1[v] + w + dists1[u] == min_1 && disth2[v] + w + dists2[u] == min_2 && disth1[v] == disth2[v]))
        {
            cout << "infinity\n";
            return;
        }
    }

    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        bool on_1 = (disth1[i] + dists1[i] == min_1);
        bool on_2 = (disth2[i] + dists2[i] == min_2);

        if (on_1 && on_2)
        {
            if (disth1[i] == disth2[i])
                cnt++;
            else if (i == s2 && disth1[s2] >= disth2[s2])
                cnt++;
            else if (i == s1 && disth2[s1] >= disth1[s1])
                cnt++;
        }
    }

    for (auto e : es)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        ll w = get<2>(e);

        bool on_1 = (disth1[u] + w + dists1[v] == min_1);
        bool on_2 = (disth2[v] + w + dists2[u] == min_2);

        if (on_1 && on_2)
        {
            if (disth1[u] < disth2[u] && disth2[v] < disth1[v])
            {
                cnt++;
            }
        }

        if (on_1 && on_2)
        {
            if (disth1[v] < disth2[v] && disth2[u] < disth1[u])
            {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}