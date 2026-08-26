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
const int MOD = 1000000007;
int mod(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int cnt = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            cnt++;
        else
            s.insert(a[i]);
    }
    int p = n - cnt;
    if (p == 0)
    {
        cout << mod(2, n - 1) << endl;
        return;
    }
    int adj = 0;
    for (int i = cnt; i < n; i++)
    {
        if (a[i] == a[i - 1]+1)
            adj++;
    }
    int base = mod(2, p - sz(s));
    int ans = 0;
    if (cnt == 0)
    {
        ans = base;
    }
    else
    {
         ans = mod(2, cnt - 1);
        ans = ans * base % MOD;
        ans = ans * (adj + 1) % MOD;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     tt()
    solve();
    return 0;
}
