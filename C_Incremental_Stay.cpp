
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l=2*n;
        vector<long long> a( l);
        for (int i = 0; i < l; i++)
            cin >> a[i];
        if (n==1)
        {
            cout << a[2*n - 1] - a[0] << endl;
            continue;
        }
        vector<long long> a1, a2;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i <l; i++)
        {
            if (i % 2 == 0)
            {
                sum1 -= a[i];
            }
            else
            {
                sum1 += a[i];
            }
        }
        a1.push_back(sum1);
        sum2 = a[l- 1] - a[0];
        for (int i = 1; i <  l - 1; i++)
        {
            if (i % 2 == 1)
            {
                sum2 -= a[i];
            }
            else
            {
                sum2 += a[i];
            }
        }
        a2.push_back(sum2);
        for(int i=1;i<l-1-i;i+=2)
        {
            a1.push_back(a1.back()-2*a[i]+2*a[l-1-i]);
        }
         for(int i=2;i<l-2-i;i+=2)
        {
            a2.push_back(a2.back()-2*a[i]+2*a[l-1-i]);
        }
        for(int i=0;i<a2.size();i++)
        {
            cout<<a1[i]<<" "<<a2[i]<<" ";
        }
        if(n&1)
        cout<<a1.back()<<endl;
        else 
        cout<<endl;}
        return 0;
    }
