#include <bits/stdc++.h>
using namespace std;

#define int long long

// Maximum sum of a subarray that crosses the middle
int maxCrossingSum(vector<int> &a, int l, int mid, int r)
{
    // Maximum suffix sum of left half
    int sum = 0;
    int leftSum = LLONG_MIN;

    for (int i = mid; i >= l; i--)
    {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    // Maximum prefix sum of right half
    sum = 0;
    int rightSum = LLONG_MIN;

    for (int i = mid + 1; i <= r; i++)
    {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }
    // Crossing subarray = left suffix + right prefix
    return leftSum + rightSum;
}

// Divide and Conquer
int maxSubarray(vector<int> &a, int l, int r)
{
    // Base case
    if (l == r)
        return a[l];

    int mid = l + (r - l) / 2;
    cout << mid << endl;

    // 1. Maximum subarray completely in left half
    int left = maxSubarray(a, l, mid);

    // 2. Maximum subarray completely in right half
    int right = maxSubarray(a, mid + 1, r);
    // 3. Maximum subarray crossing the middle
    int cross = maxCrossingSum(a, l, mid, r);

    return max({left, right, cross});
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << maxSubarray(a, 1, n) << '\n';

    return 0;
}