#include <bits/stdc++.h>
using namespace std;

int dp[1<<15];

int solve(int mask, vector<vector<int>>& cost, int n) {
    if (mask == (1<<n)-1) return 0;

    if (dp[mask] != -1) return dp[mask];

    int worker = __builtin_popcount(mask);
    int ans = INT_MAX;

    for (int j = 0; j < n; j++) {
        if (!(mask & (1<<j))) {
            ans = min(ans,
                cost[worker][j] +
                solve(mask | (1<<j), cost, n)
            );
        }
    }

    return dp[mask] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    memset(dp, -1, sizeof(dp));

    cout << solve(0, cost, n) << endl;

    return 0;
}
