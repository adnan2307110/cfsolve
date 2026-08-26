#include <bits/stdc++.h>
// code by adnan prb type graph dsu take help for syntax
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
    map<int, bool> mp;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = true;
        if (a[i] == 0)
            cnt++;
    }
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        bool move=false;
        if (a[l] == l + 1 || (a[l] == 0 && (cnt == 1 && mp[l + 1]==false)))
        {
            l++;
            move=true;
        }
        if (a[r] == r + 1 || (a[r] == 0 && (cnt == 1 && mp[r + 1]==false)))
        {
            r--;
            move=true;
        }
        if(!move) break;
    }
    if (l > r)
        cout << 0 << endl;
    else
        cout << r - l + 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}