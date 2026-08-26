
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
    vi p(n);
    cin >> p;
    string x;
    cin >> x;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '0')
            c++;
    }
    if (c == n)
    {
        cout << 0 << endl;
        return;
    }
    int a = 0, b = 0;
    while (p[a] != 1)
    {
        a++;
    }
    while (p[b] != n)
    {
        b++;
    }
    if (x[0] == '1' || x[n - 1] == '1' || x[a] == '1' || x[b] == '1')
    {
        cout << -1 << endl;
        return;
    }
    a++;
    b++;
    vector < pair <int, int >> v = {
        {1, a},
        {1, b},
        {a, n},
        {b, n},
        {min(a, b), max(a, b)}
    };
    cout<<5<<endl;
    for(auto &[x,y]:v)
    {
        cout<<x<<sp<<y<<endl;
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
