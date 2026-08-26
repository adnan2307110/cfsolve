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
const ll mod = 1e9 + 7;
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
ostream &operator<<(ostream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is << element;
    return is;
}
void solve()
{
    ll a, b, n;
    cin >> a >> b >> n;
    if (n == 1 || a == b)
    {
        cout << 1 << endl;
        return;
    }
    if (a >= b * n)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
    {
        solve();
    }
    return 0;
}