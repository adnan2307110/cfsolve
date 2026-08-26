#include <bits/stdc++.h>
// code by adnan tle prb and then optimize then debug issue
// numbertheory target to make 5 & 2 modulo equal;
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
       vector<int> c;
    c.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) c.push_back(a[i]);
    }
    if(sz(c)==1)
    {
        cout<<1<<endl;
        return;
    }
    vi b;
    b.pb(c[0]);
    for (int i = 1; i <sz(c)-1; i++)
    {
        if ((c[i] > c[i + 1] && c[i] > c[i - 1]) || (c[i] < c[i + 1] && c[i] < c[i - 1]))
        {
            b.pb(c[i]);
        }
    }
    b.pb(c[n - 1]);
    cout << sz(b) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}