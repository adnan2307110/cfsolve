#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    string ans;
    ans += grid[0][0];

    vector<pair<int, int>> cur;
    cur.push_back({0, 0});

    for (int step = 0; step < 2 * n - 2; step++)
    {
        char mn = 'Z' + 1;
        for (auto [i, j] : cur)
        {
            if (i + 1 < n)
                mn = min(mn, grid[i + 1][j]);

            if (j + 1 < n)
                mn = min(mn, grid[i][j + 1]);
        }

        vector<pair<int, int>> next;
        for (auto [i, j] : cur)
        {
            if (i + 1 < n && grid[i + 1][j] == mn)
                next.push_back({i + 1, j});

            if (j + 1 < n && grid[i][j + 1] == mn)
                next.push_back({i, j + 1});
        }

        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());

        ans += mn;
        cur = next;
    }

    cout << ans << '\n';

    return 0;
}