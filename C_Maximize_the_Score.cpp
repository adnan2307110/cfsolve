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
    vi a(2 * n+1);
    for(int i=1;i<=2*n;i++) cin>>a[i];
    vector<int> f(n + 1, -1);
    for (int i =1; i <=2*n; i++)
    {
        int x = a[i];

        if (f[x] == -1)
            f[x] = i;
    }
    vi dp(2 * n + 1);
    for (int i =1; i <=2 * n; i++)
    {

        int l = i - f[a[i]] + 1;
        if (l >= 0)
        {
            dp[i] = max(dp[i - 1] + 1, dp[f[a[i]] - 1] + l * l);
        }
    }
    cout << dp[2 * n] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
