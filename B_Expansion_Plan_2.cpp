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
const ll mod = 1e9 + 7;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    if (x == 0 && y == 0)
    {
        cout << "YES" << endl;
        return;
    }
    x = abs(x);
    y = abs(y);
    set<pair<ll, ll>> p;
    p.insert({0, 0});
    for (auto c : s)
    {
        set<pair<ll, ll>> n;
        for (auto &a : p)
        {
            ll x = a.first;
            ll y = a.second;

            if (c == '4')
            {
                n.insert({x + 1, y});
                n.insert({x, y + 1});
            }
            else
            {
                n.insert({x + 1, y});
                n.insert({x, y + 1});
                n.insert({x + 1, y + 1});
            }
        }
        p = n;
        if (p.count({x, y}))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
