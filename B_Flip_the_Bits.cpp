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
    string a, b;
    cin >> a >> b;
    vector<int> pref0(n, 0), pref1(n, 0);
    if (a[0] == '0')
        pref0[0] = 1;
    else
        pref1[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pref0[i] = pref0[i - 1];
        pref1[i] = pref1[i - 1];
        if (a[i] == '0')
            pref0[i]++;
        else
            pref1[i]++;
    }
    bool f =false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (f)
            a[i] = (a[i] == '0') ? '1' : '0';
        if (a[i] != b[i])
        {
            if (pref0[i] != pref1[i])
            {
                no;
                return;
            }
            f = !f;
        }
    }
    yes;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}