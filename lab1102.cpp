#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class point
{
    int x, y;

    friend class Triangle;

public:
    void seT(int a, int b)
    {
        x = a;
        y = b;
    }
    void geT()
    {
        cout << "P(" << x << "," << y << ")" << endl;
    }
    // friend class Triangle;
};
class Triangle
{

public:
    void area(point &p1, point &p2, point &p3)
    {
        int a = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
        float x = 0.5 * fabs(a);
        cout << fixed << setprecision(4);
        cout << "area=" << x << endl;
    }
};
int main()
{
    point p1, p2, p3;
    Triangle aRea;
    p1.seT(0, 0);
    p2.seT(4, 0);
    p3.seT(0, 3);
    p1.geT();
    p2.geT();
    p3.geT();
    aRea.area(p1, p2, p3);
    return 0;
}