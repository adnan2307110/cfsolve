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
const ll mod = 1e9 + 7;
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
ostream &operator<<(ostream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is << element;
    return is;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    int bit1 = floor(log2(a), 1) + 1;
    int bit2 = floor(log2(b), 1) + 1;
    if (bit2 > bit1)
    {
        cout << -1 << endl;
        return;
    }
    vi v;
    for (int i = 0; i <= bit1; i++)
    {
        if (1ll << i & a)
        {
            if (1ll << i & b)
            {

            }
            else
            {
                ll x = 1ll << i;
                v.pb(x);
            }
        }
        else if (1ll << i & b)
        {
            if (1ll << i & a)
            {
            }
            else
            {
                ll y = 1ll << i;
                v.pb(y);
            }
        }
    }
    cout << sz(v) << endl;
    for (auto x : v)
        cout << x << sp;
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}