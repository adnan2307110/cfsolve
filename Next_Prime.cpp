#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
#define vi = vector<int>;
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
const long long int N = 1e7;
vector<bool> dp(N + 1, true);
vector<ll> prime;
void check()
{
    dp[0] = false;
    dp[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (dp[i])
        {
            for (int j = i * i; j <= N; j += i)
                dp[j] = false;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (dp[i])
            prime.pb(i);
    }
}
void solve()
{
    ll n;
    cin >> n;
    int i = 0;
    while (!(prime[i] > n))
    {
        i++;
    }
    cout << prime[i] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    check();
    tt()
        solve();
    return 0;
}
