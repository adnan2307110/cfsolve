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
void dijkstra(int src, vector<vector<pair<int, int>>> &g, int v)
{
    vector<int> dis(v, INF);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    // p.push(dis[u],u);
    p.push({dis[src], src});
    while (!p.empty())
    {
        pair<int, int> cur = p.top();
        p.pop();
        int d = cur.first;
        int u = cur.second;

        for (auto edge : g[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                p.push({dis[v], v});
            }
        }
    }
    for (auto x : dis)
    {
        cout << x << " ";
    }
    cout << endl;
}

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dijkstra(0, g, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
