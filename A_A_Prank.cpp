
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
    int t;
    int mx = 1;
    int c = 1;
    int b = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] == 1)
        {
            mx++;
        }
        else
        {
            if (mx > c)
            {
                c = mx;
                b = i;
            }
            mx = 1;
        }
    }
    if (mx > c)
    {
        c = mx;
        b = i;
    }
    if (mx == c && a[b - c] != 1)
    {
        c = mx;
        b = i;
    }

    if (c == 1)
    {
        cout << 0 << endl;
        return;
    }
    // cout << b << sp << c << endl;
    if (a[b - 1] == 1000 || a[b - c] == 1)
    {
        cout << c - 1 << endl;
        return;
    }

    else
        cout << c - 2 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
