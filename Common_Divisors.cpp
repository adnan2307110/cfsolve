
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
const ll mod = 1000000007;
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
    int mx = *max_element(all(a));
    vi f(mx + 1, 0);
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
    }
    for (int i = mx; i >= 1; i--)
    {
        int c = 0;
        for (int g =i; g <= mx; g +=i)
        {
            c += f[g];
            if (c >= 2)
                break;
        }
        if (c >= 2)
        {
            cout << i << endl;
            return;
        }
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
