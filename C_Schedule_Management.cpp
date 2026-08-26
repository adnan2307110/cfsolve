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
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vi a(m);
    cin >> a;
    map<int, int> f;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 0;
    }
    for (auto x : a)
        f[x]++;
    ll ans = 0, low = 1, high = 2 * m;
    while (low <= high)
    {
        bool flag = false;
        ll help = 0, left = 0;
        ll mid = low + (high - low) / 2;
        for (int i = 1; i <= n; i++)
        {
            if (mid > f[i])
                help += (mid - f[i]) / 2;
            else
                left += f[i] - mid;
        }
        flag = (help >= left);
        if (flag)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
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