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
    int cnt = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 0)
        {
            cnt++;
        }
        if (a[i] == 0 && b[i] == 1)
        {
            cnt1++;
        }
        if (a[i] == 1 && b[i] == 1)
            cnt2++;
        if (a[i] == 0 && b[i] == 0)
            cnt3++;
    }
    if (cnt == 0 && cnt1 == 0)
    {
        cout << 0 << endl;
    }
    if (cnt != 0)
    {
        if (cnt % 2 == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    if (cnt == 0 && cnt1 != 0)
    {
        if (cnt2 != 0 && cnt3 != 0)
            cout << 2 << endl;
        else
            cout << -1 << endl;
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
