#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int i, j, k;
    int x;
    int t, n;

    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1));

    for (i = 1; i <= n; i++)
    {
        cin >> dp[i][i].second;
        dp[i][i].first = 0;
    }

    for (int len = 2; len <= n; len++)
    {
        for (i = 1; i <= (n - len + 1); i++)
        {
            j = i + len - 1;
            dp[i][j].first = INT_MAX;

            for (k = i; k < j; k++)
            {

                x = dp[i][k].first + dp[k + 1][j].first + dp[i][k].second * dp[k + 1][j].second;
                if (x < dp[i][j].first)
                {
                    dp[i][j].first = x;
                    dp[i][j].second = (dp[i][k].second + dp[k + 1][j].second) % 100;
                }
            }
        }
    }
    cout << dp[1][n].first << endl;

    return 0;
}

