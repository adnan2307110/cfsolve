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
    int n, k;
    cin >> n >> k;
    string s;
    if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                s += '0';
            else
                s += '1';
        }
    }
    else
    {
        int v = n / 2 + (n % 2);
        int u = n - v;
        if (v + u - 2 < k)
        {
            cout << -1 << endl;
            return;
        }
        int c = (v + u - 2 - k);
        if (c == 1)
        {
            v = v - c;
            u = u;
        }
        else
        {
            v = v - (c / 2 + c % 2);
            u = u - (c / 2);
        }
        s = string(v, '1');
        s += string(u, '0');
        int p = 0;
        while (sz(s) != n)
        {
            if (p % 2 == 0)
                s += '1';
            else
                s += '0';
            p++;
        }
    }
    cout << s << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
