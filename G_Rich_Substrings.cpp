#include <bits/stdc++.h>
using namespace std;
#define tt()  \
    long long t;    \
    cin >> t; \
    while (t--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((long long)a.size())
#define F first
#define S second
#define __lcm(a, b) (a * b) / __gcd(a, b)
using vi = vector<long long>;
using pii = pair<long long, long long>;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define floor(a, b) (a / b)
#define round(a, b) ((a + (b / 2)) / b)
#define ceil(a, b) ((a + b - 1) / b)
#define sp ' '
#define endl '\n'
#define rep1(a, n) for (long long i = a; i < (n); ++i)
#define rep2(i, a, b) for (long long i = a; i <= b; ++i)
istream &operator>>(istream &is, vector<long long> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}

void solve()
{
   long long n,q;
   cin>>n>>q;
   string s;
   cin>>s;
   map<char,long long>mp;
   long long i=0;
   vector<long long>v;
   while(i+3<s.size())
   {
      map<char,long long>mp;
      for(long long j=i;j<i+3;j++)
      {
        mp[s[j]]++;
      }
      bool ans=false;
      for(auto j:mp)
      {
        if(j.second>1)
        {
            ans=true;
            break;
        }
      }
      if(ans)
      {
        v.push_back(1);
      }
      else{
        v.push_back(0);
      }
      i++;
   }
   vector<long long>pre(n);
   pre[0]=v[0];
   for(long long i=1;i<v.size();i++)
   {
       pre[i]=pre[i-1]+v[i];
   }
   long long j=pre[pre.size()-4];
   for(long long i=n-3;i<n;i++)
   {
       pre[i]=j;
   }
   while (q--)
   {
    long long l,r;
    cin>>l>>r;
    l=max(0LL,l-1);
    r=max(0LL,r-3);
    long long ans=pre[r]-pre[l];
    if(ans>0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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
