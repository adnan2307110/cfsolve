
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
ll fact(int n){
    ll res=1;
    for (int i = 2; i <=n; i++)
    {
        res=(res*i)%MOD;
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    vi a(n);
    cin >> a;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    ll ans=a[0];
    for (int i =1; i <n; i++)
    {
        ans&=a[i];
    }
    int k=mp[ans];
    ll res=(k%MOD)*((k-1)%MOD);
    int b=n-2;
    ll f=fact(b);
    res=(res%MOD*(f%MOD))%MOD;
    cout<<res%MOD<<endl;
 
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}