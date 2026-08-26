#include <bits/stdc++.h>
using namespace std;
typedef double dl;
dl f(dl x)
{
    return x * x * x - 3 * x * x + 5 * x - 9;
}
int main()
{

    dl l, r, tolerance;
    cout << "Input: ";
    cin >> l >> r >> tolerance;
    dl a = 0, b = 0;
    bool flag = true;
    for (dl x = l; x <= r; x += .2)
    {
        if (f(x) == 0)
        {
            cout << "root " << 0 << endl;
            return 0;
        }
        if (f(x) * f(x + .2) < 0)
        {
            a = x;
            b = x + .2;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Not possible to find root in that range " << endl;
        return 0;
    }

    if (f(a) * f(b) > 0)
    {
        cout << "Invalid" << endl;
        return 0;
    }
    dl c = 0;
    int i = 0;
    while (true)
    {
        i++;

        c = (a + b) / 2;
        cout << fixed << setprecision(4);
        cout << "Iteration:" << i << " "
             << "a :" << a << " "
             << "b :" << b << " "
             << "c :" << c << " "
             << "f(c) :" << f(c) << endl;
        if (fabs(f(c)) < tolerance)
            break;
        if (f(c) < 0)
            a = c;
        else
            b = c;
    }
    cout << "root :" << c << endl;
    return 0;
}
