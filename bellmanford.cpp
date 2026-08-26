#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)a.size())
#define F first
#define S second
#define __lcm(a, b) (a * b) / __gcd(a, b)
using vi = vector<int>;
using pii = pair<int, int>;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define floor(a, b) (a / b)
#define round(a, b) ((a + (b / 2)) / b)
#define ceil(a, b) ((a + b - 1) / b)
#define sp ' '
#define endl '\n'
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
istream &operator>>(istream &is, vector<int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
const int INF = 1e18;
void bellman_ford(int v, vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dis(v, INF);
    dis[src] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (int u = 0; u < v; u++)
        {
            for (auto x : adj[u])
            {
                int v = x.first;
                int w = x.second;
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
    }
    for (int u = 0; u < v; u++)
    {
        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (dis[v] > dis[u] + w)
            {
                cout<<"negative cyle"<<endl;
                return;
            }
        }
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    bellman_ford(n, adj, 0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
