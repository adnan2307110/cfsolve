#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const int MOD = 998244353;
const int N = 5000 + 5;
vector<int>dp(N,0);
vector<int>cnt(N,0);
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
#define  vi = vector<int>;
#define pii = pair<int, int>;
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
int addmod(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
void solve()
{
    ll n;
    cin >> n;
     for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int max_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > max_cnt)
            max_cnt = cnt[i];
    }
    for (int j = 0; j <= n; j++)
       dp[j] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (cnt[i])
        {
            for (int j = n; j >= cnt[i]; j--)
            {
                ll add = 1LL * cnt[i] * dp[j - cnt[i]] % MOD;
                dp[j] = addmod(dp[j], (int)add);
            }
        }
    int ans = 0;
    for (int j = max_cnt; j <= n; ++j)
    {
        ans = addmod(ans, dp[j]);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
