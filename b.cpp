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
using vi = vector<double>;
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
const ll mod = 1e9 + 7;
istream &operator>>(istream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is >> element;
    return is;
}
ostream &operator<<(ostream &is, vector<long long int> &v)
{
    for (auto &element : v)
        is << element;
    return is;
}
void solve()
{
    int n;
    cin >> n;
     vi a;
    while (n--)
    {
    int i;
    double x,p,q;

        cin>>i;
        if(i==1)
        {
            cin>>x;
            a.pb(x);
        }
        else if(i==2)
        {
            cin>>x;
            for(int j=0;j<sz(a);j++)
            {
                a[j]=a[j]+x;
            }
            
        }
        else if(i==3)
        {
            cin>>p>>q;
            for(int j=0;j<sz(a);j++)
            {
                a[j]=a[j]*(p/q);
            }
        
        }
        else
        {
            cin>>x;
            for(int j=0;j<x;j++)
            {
                cout<<ll(a[j])<<sp;
            }
            cout<<endl;

        }
    }
    
 
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tt() solve();
    return 0;
}
