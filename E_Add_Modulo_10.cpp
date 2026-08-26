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
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}

void solve()
{
    ll n;
    cin >> n;
    vi a(n);
    cin >> a;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 5 == 0)
        {
            cnt++;
        }
    }
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
        {
            while(a[i]%10!=0)
            {
                a[i]+=a[i]%10;
            }
        }
        set<ll>x(all(a));
        if(x.size()==1)
        yes;
        else 
        no;
    }
    else if (cnt == 0)
    {
        for (int i = 0; i < n; i++)
        {
            while (a[i] % 10 != 2)
            {
                a[i] += a[i] % 10;
            }
        }
        bool flag2 = true;
        for (int i = 1; i < n; i++)
        {
            if (abs(a[i] - a[i - 1]) % 20 != 0)
            {
                flag2 = false;
            }
        }
        if (flag2)
            yes;
        else
            no;
    }
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}