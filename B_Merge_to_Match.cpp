#include <bits/stdc++.h>
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    cin >> a;
    cin >> b;
    sort(all(a));
    sort(all(b));
    vi c = a;
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 0; i < m; i++)
    {
        int l = lower_bound(a.begin(), a.end(), b[i]) - a.begin() - 1;
        int r = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (l == -1 || r == a.size())
        {
            flag1 = false;
            break;
        }

        a.erase(a.begin() + r);
        a.erase(a.begin() + l);
    }
    reverse(all(b));
    for (int i = 0; i < m; i++)
    {
        int l = lower_bound(c.begin(), c.end(), b[i]) - c.begin() - 1;
        int r = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
        if (l == -1 || r == c.size())
        {
            flag2 = false;
            break;
        }
        c.erase(c.begin() + r);
        c.erase(c.begin() + l);
    }

    if (flag1 || flag2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
