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
    ll n;
    cin >> n;
    vi v(n);
    cin>>v;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = {v[i], i};
    }
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++)
    {
        L[i] = (i - 1 + n) % n;
        R[i] = (i + 1) % n;
    }
    sort(all(a));
    vector<int> s(n, 1);
    int b = n;
    ll c = 0;
    for (auto &p : a)
    {
        if (b <= 1)
            break;
        ll idx = p.second;
        if (s[idx] == 0)
            continue;
        ll left = L[idx];
        ll right= R[idx];
        c += min(v[left], v[right]);
        s[idx] = 0;
        R[left] = right;
        L[right] = left;
        b--;
    }
    cout << c << endl;
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