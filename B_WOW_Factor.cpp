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
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vi prf(n,0);
    vi suf(n,0);
    for (int i =1; i <n; i++)
    {
        prf[i]=prf[i-1];
        if(s[i]=='v'&&s[i-1]=='v')
        prf[i]++;
    }
    reverse(all(s));
      for (int i =1; i <n; i++)
    {
        suf[i]=suf[i-1];
        if(s[i]=='v'&&s[i-1]=='v')
        suf[i]++;
    }
    reverse(all(suf));
    reverse(all(s));
    ll ans=0;
    for (int i =0; i <n; i++)
    {
        if(s[i]=='o')
        ans+=prf[i]*suf[i];
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //tt()
        solve();
    return 0;
}