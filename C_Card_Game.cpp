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
#define mod 1000000007LL
inline long long addmod(long long a, long long b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
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
    string s;
    cin >> s;
    char r = s[n - 1];
    char l = s[0];
    char p = s[n - 2];
    if (r == l)
    {
        if (r == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
    }
    int i = 0;
    while (l == s[i])
    {
        i++;
    }
    if (i == n - 1)
    {
        if (l == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
    }
    else
    {
        if (r == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
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
