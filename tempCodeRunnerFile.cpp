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
    int n;
    cin >> n;
    vi a(n), b(n);
    cin >> a;
    cin >> b;
    int s = 0;
    int ans = 0;
    if (n == 1 && a[0] == b[0])
    {
        cout << 0 << endl;
        return;
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            s += a[i];
            flag = true;
        }
        else
        {
            if (s == 0 && flag)
            {
                cout << -1 << endl;
                return;
            }
            else if (s != 0 && s % 2 == 0)
            {
                ans += 2;
            }
            else if (s % 2 == 1)
            {
                ans += 1;
            }
            s = 0;
            flag = false;
        }
    }
    if (flag && s == 0)
    {
        cout << -1 << endl;
        return;
    }
    else if (s != 0 && s % 2 == 0)
    {
        ans += 2;
    }
    else if (s % 2 == 1)
    {
        ans += 1;
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
