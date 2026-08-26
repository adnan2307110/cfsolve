
#include <bits/stdc++.h>
// code by adnan
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
#define MOD 1000000007LL
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
      for (int i =1; i <=m; i++)
    {
        if(mp[i]==0)
        {
            no;
            return;
        }
    }
    int cnt=0;
    for (int i = 0; i <n; i++)
    {
        bool f=true;
        for(int num:a[i])
        {
            if(mp[num]==1)
            {
                f=false;
                break;
            }
        }
        if(!f) cnt++;
    }
    if(n-cnt>=2)
    {
        yes;
    }
    else
    {
        no;
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