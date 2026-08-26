#include <bits/stdc++.h>
//code by adnan tle prb and then optimize then debug issue
//numbertheory target to make 5 & 2 modulo equal;
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
    ll n, m;
    cin >> n >> m;
    ll k = 1;
      int cn2=0;
      ll tp=n;
      while (tp%2==0)
      {
        cn2++;
        tp/=2;
      }
      tp=n;
      int cn5=0;
        while (tp%5==0)
      {
        cn5++;
        tp/=5;
      }
      while (cn2>cn5&&k*5<=m)
      {
        k*=5;
        cn5++;
      }
         while (cn2<cn5&&k*2<=m)
      {
        k*=2;
        cn2++;
      }
      while (k*10<=m)
      {
        k*=10;
      }
    if(k>1)
    {k=(m/k)*k;
    cout<<n*k<<endl;}
    else
    cout<<n*m<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt()
        solve();
    return 0;
}