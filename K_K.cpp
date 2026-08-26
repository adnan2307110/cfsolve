#include <bits/stdc++.h>
typedef long long int ll;
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
    ll n;
    vi a(n), b(n), t(n);
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++)
    {
        t[i] = a[i] - b[i];
    }
    int mx = *max_element(all(t));
    vi out;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == mx)
        {
            out.pb(i + 1);
        }
        cout << sz(out) << endl;
        for (auto x : out)
        {
            cout << x << sp;
        }
    }
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
