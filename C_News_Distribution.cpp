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
vi par, sz;
int find(int a)
{
    if (a == par[a])
        return a;
    else
        return par[a] = find(par[a]);
}
void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    par.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    sz.resize(n, 1);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int first;
        if (k)
            cin >> first;
        first--;
        for (int i = 1; i < k; i++)
        {
            int a;
            cin >> a;
            a--;
            join(first, a);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sz[find(i)] << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}