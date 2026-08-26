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
using vi = vector<int>;
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
    vvi a(n);
    int t = n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i].resize(x);
        for (int j = 0; j < x; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < a[i].size(); j++)
        {
            if (mp[a[i][j]] > 1)
                continue;
            ok = false;
            break;
        }
        if (ok)
        {
            possible = true;
            break;
        }
    }

    if (possible)

        yes;

    else
        no;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}