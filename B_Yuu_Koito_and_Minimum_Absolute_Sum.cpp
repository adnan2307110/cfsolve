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
    ll n;
    cin >> n;
    vi a(n);
    cin >> a;
    bool l = (a[0] == -1);
    bool h = (a[n - 1] == -1);
    ll ans;
    if (l || h)
    {
        ans = 0;
    }
    else
    {
        ans = llabs(a[0] - a[n - 1]);
    }
    if (l && h)
    {
        a[0] = 0;
        a[n - 1] = 0;
    }
    else if (!l && h)
        a[n - 1] = a[0];
    else if (l && !h)
        a[0] = a[n - 1];
    for (int i = 0; i < n; i++)
        if (a[i] == -1)
            a[i] = 0;
    cout << ans << endl;
    for (auto x : a)
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
