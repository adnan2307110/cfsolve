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
#define MAX_COLOUR 100000
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
    vi a(n);
    cin >> a;
    sort(all(a));
    multiset<ll, greater<ll>> s;
    map<ll, ll> f;
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
    }
    int t = 0;
    ll ans = 0;
    vi p;
    for (auto x : f)
    {
        if (x.second & 1)
        {
            ans += x.first * (x.second - 1);
            s.insert(x.first);
            t += x.second - 1;
        }
        else
        {
            t += x.second;
            ans += x.first * x.second;
        }
    }
    int j = 1;
    if (ans)
    {
        for (auto i = s.begin(); i != s.end(); i++)
        {
            if (j == sz(s))
            {
                if (ans > *i)
                {
                    cout << ans + *i << endl;
                    return;
                }
            }
            else
            {
                auto i2 = i;
                i2++;
                if (ans + *i2 > *i)
                {
                    cout << ans + *i2 + *i << endl;
                    return;
                }
                j++;
            }
        }
    }
    if (t == 2)
    {
        cout << 0 << endl;
    }
    else
        cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
