#include <bits/stdc++.h>
// adnan hossain
// adnan
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
int prims(vector<vector<pair<int, int>>> &adj, int src, int v)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<bool> visited(v, false);
    pq.push({0, src,-1});
    vector<tuple<int, int, int>> tree;
    int res = 0;
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int wt =get<0>(x);
        int u = get<1>(x);
        int parent=get<2>(x);

        if (visited[u])
            continue;
        if(parent!=-1)
        {
            tree.push_back({parent,u,wt});
        }
        res += wt;
        visited[u] = true;
        for (auto v : adj[u])
        {
            if (!visited[v.first])
            {
                pq.push({v.second,v.first,u});
            }
        }
    }
    for(auto v:tree)
    {
        cout<<get<0>(v)<<"=>"<<get<1>(v)<<"weight"<<get<2>(v)<<"=> "
    }
    return res;
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
        adj[v].pb({u, w});
    }
    int ans = prims(adj, 0, n);
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
