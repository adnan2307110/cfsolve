#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    long long i=1;
    while(t--)
    {
        cout<<"Case "<<i<<":"<<endl;
        i++;
        long long n,q;
        cin>>n>>q;
        vector<long long>v(n);
        for(long long i=0;i<n;i++)
        {
            cin>>v[i];
        }

        while(q--)
        {
            long long type;
            cin>>type;
            if(type==1)
            {
                long long x,y;
                cin>>x>>y;
            }
            else{
                long long idx;
                cin>>idx;
                idx--;
                cout<<v[idx]<<endl;
            }
        }
    }
    return 0;
}