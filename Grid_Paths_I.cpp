
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
#define mod 1000000007
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    if (v[n - 1][n - 1] == '.')
        dp[n - 1][n - 1] = 1;
    else
        dp[n - 1][n - 1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
         {
            if (i == n - 1 && j == n - 1)
                continue;
            if (v[i][j] == '*')
                dp[i][j] = 0;
            else
            {
                int ans1 = (i + 1 < n ? dp[i + 1][j] : 0);
                int ans2 = (j + 1 < n ? dp[i][j + 1] : 0);
                dp[i][j] = (ans1 + ans2) % mod;
            }
        }
    }
    cout << dp[0][0] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
