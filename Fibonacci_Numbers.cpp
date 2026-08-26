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
const ll mod = 1e9 + 7;
pair<ll, ll> fib(ll n)
{
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll a = p.first;
    ll b = p.second;
    ll c = (a * ((2 * b % mod - a + mod) % mod)) % mod;
    ll d = ((a * a) % mod + (b * b) % mod) % mod;

    if (n & 1)
    {
        return {d, (c + d) % mod};
    }
    else
    {
        return {c, d};
    }
}
void solve()
{
    ll n;
    cin >> n;
    cout << fib(n).first % mod << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //tt()
        solve();
    return 0;
}
