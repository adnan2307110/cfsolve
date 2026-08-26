#include <bits/stdc++.h>
using namespace std;
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
const int mx = 200005;
vector<vector<int>> g(mx);
int dp[mx];
int depth[mx];
int ans;
void dfs(int v)
{
    int m1 = depth[v];
    int m2 = depth[v];
    dp[v] = depth[v];
    for (auto child : g[v])
    {
        depth[child] = depth[v] + 1;
        dfs(child);
        dp[v] = max(dp[v], dp[child]);
        if (dp[child] >= m1)
        {
            m2 = m1;
            m1 = dp[child];
        }
        else if (dp[child] >= m2)
        {
            m2 = dp[child];
        }
    }
    ans += m2 - depth[v] + 1;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    ans = 0;
    depth[1] = 0;
    dfs(1);
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     tt()
    solve();
    return 0;
}
