#include <iostream>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
int main()
{
    ll x = 2;
    for (int i = 1; i <= 3; i++)
    {
        x *= i;
    }
    cout << x << endl;

    return 0;
}