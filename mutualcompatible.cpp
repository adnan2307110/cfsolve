#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);

    for (auto &[s, f] : a) {
        cin >> s >> f;
    }

    // Sort by finish time
    sort(a.begin(), a.end(),
         [](auto &x, auto &y) {
             return x.second < y.second;
         });

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (a[j].second <= a[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}