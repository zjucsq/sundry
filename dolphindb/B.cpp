#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// check t is enough or not
int solve(int t, int m, vector<int> &read, vector<int> &cal) {
    int n = read.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0x3fffffff));
    for (int i = 0; i <= m; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int cal_cost = (read[i - 1] + 2 * t - 1) / (2 * t) + (cal[i - 1] + t - 1) / t;
        int read_cost = (read[i - 1] + t - 1) / t + (cal[i - 1] + 2 * t - 1) / (2 * t);
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + (j % 2 == 0 ? cal_cost : read_cost));
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (j % 2 == 0 ? cal_cost : read_cost));
            }
        }
    }
    // cout << dp[n][m] << endl;
    return dp[n][m];
}

int main()
{
    int n, m, T;
    cin >> n >> m >> T;
    vector<int> read(n), cal(n);
    for (int i = 0; i < n; ++i) {
        cin >> read[i] >> cal[i];
    }

    int l = 1;
    int r = 0x3fffffff;
    while (l < r) {
        int mid = (l + r) / 2;
        if (solve(mid, m, read, cal) > T) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        // cout << l << ' ' << r << endl;
    }
    cout << l + 1 << endl;
    return 0;
}

/*
6 2 20
1 1
2 3
2 2
4 3
1 4
7 2

2
*/
