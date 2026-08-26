
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
    ll n, w;
    cin >> n >> w;
    vi a(n);
    cin >> a;
    vector<int> m(25, 0);
    for (int i = 0; i < n; i++)
    {
        int x = log2(a[i]);
        m[x]++;
    }
    int h = 0;
    int q = 0;
    while (n > q)
    {
        ll W = w;
        for (int i = 20; i >= 0; i--)
        {
            while (m[i] > 0 && (1 << i) <= W)
            {
                W -= (1 << i);
                m[i]--;
                q++;
            }
        }
        h++;
    }

    cout << h << endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}
