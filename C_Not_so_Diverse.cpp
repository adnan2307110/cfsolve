#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tt() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)a.size())
#define F first
#define S second
#define __lcm(a,b) (a*b)/__gcd(a,b)
using vi = vector<int>;
using pii = pair<int, int>; 
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define floor(a, b) (a / b)
#define round(a, b) ((a + (b / 2)) / b)
#define ceil(a, b) ((a + b - 1) / b)
#define sp ' '
#define endl '\n'
#define rep1(a,n) for (int i = a; i < (n); ++i)
#define rep2(i,a,b) for(int i = a; i <= b ; ++i)
istream& operator>>(istream& is, vector<int>& v) {
    for (auto& element : v) is >> element; 
    return is;
}

void solve() {
  
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    if(mp.size()<=k)
    {
        cout<<0<<endl;
        return;
    }

    vector<int>v;
    for(auto i:mp)
    {
        v.push_back(i.second);
    }
    sort(v.begin(),v.end());
    int bad=mp.size()-k;
    int ans=0;
    for(int i=0;i<bad;i++)
    {
        ans+=v[i];

    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // tt()
    solve();
    return 0;
}
