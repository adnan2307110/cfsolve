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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi dp;
    for (int i = 0; i < n; i++)
    {

        // if (dp[v[i].second] >= dp[v[i].second - 1])

        // if (v[v[i].second].first > v[v[i].second - 1].first)
        // {
        //     dp[v[i].second] = dp[v[i].second - 1] + 1;
        //     dp[v[i].second + 1] = max(dp[v[i].second + 1], dp[v[i].second]);
        //     v[v[i].second + 1] = max(v[v[i].second], v[v[i].second + 1]);
        //     ans = max(ans, dp[v[i].second]);
        // }
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (pos == dp.size())
            dp.pb(a[i]);
        else
            dp[pos] = a[i];
    }
    cout << dp.size() << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
