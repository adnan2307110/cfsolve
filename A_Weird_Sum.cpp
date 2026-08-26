#include <bits/stdc++.h>
typedef long long int ll;
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
using vi = vector<long long int>;
using vvi = vector<vi>;
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
#define MAX_COLOUR 100000
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
ll calsum(vector<int> &v)
{
    sort(all(v), greater<>());
    int n = v.size();
    ll ans = 0;
    for (int i = 0, j = n - 1; i < n; i++, j -= 2)
    {
        ans += 1ll * j * v[i];
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    vector<vector<int>> r(MAX_COLOUR);
    vector<vector<int>> c(MAX_COLOUR);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r[g[i][j]].pb(i);
            c[g[i][j]].pb(j);
        }
    }
    ll ans = 0;
    for (int i = 0; i < MAX_COLOUR; i++)
    {
        if (!r[i].empty())
            ans += calsum(r[i]);
        if (!c[i].empty())
            ans += calsum(c[i]);
    }

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