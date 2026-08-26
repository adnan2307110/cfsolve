#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Employee
{
string name;
int id;
public:
    Employee(string n ,int i):name(n),id(i)
    {
        cout<<"1st class"<<endl;
    }};
class work:virtual public Employee
{float wh;
float rh;
public:
work(string n ,int id,float a,float b):Employee(n,id),wh(a),rh(b)
{
    cout<<"work class"<<endl;
}
};
class performance: virtual public Employee
{
    float ratting;
    public:
    performance(float x):ratting(x)
    {
        cout<<"in performance class"<<endl;
    }
};
class salary:public work,public performance
{
float sl;
public:
salary(string name,int id,float wh,float rh,float ratting):Employee(name,id),performance(ratting),work(name,id,wh,rh)
{
    sl=wh*rh+ratting*1000;
    cout<<sl<<endl;
}
};
int main()
{salary s("adnan",110,15.4,9,10);
    return 0;
}
