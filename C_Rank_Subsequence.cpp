#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int l, r, u, v;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<Node> a(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].l >> a[i].r
                >> a[i].u >> a[i].v;
        }

        int ans = 0;

        // Try every possible final length m
        for (int m = 1; m <= n; m++)
        {
            int j = 0;

            for (int i = 1; i <= n; i++)
            {
                int pos = j + 1;

                // left rank condition
                bool left_ok =
                    (pos < a[i].l || pos > a[i].r);

                if (!left_ok)
                    continue;

                // right rank
                int right = m - pos + 1;

                // right rank must NOT be in [u, v]
                bool right_ok =
                    (right < a[i].u || right > a[i].v);

                if (!right_ok)
                    continue;

                // Take this element
                j++;

                if (j == m)
                    break;
            }

            if (j == m)
                ans = m;
        }

        cout << ans << '\n';
    }

    return 0;
}