#include<bits/stdc++.h>
using namespace std;

int palindrom(string s) {
    int len = s.length();
    int dp[len][len];

    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int k = 2; k <= len; k++) {
        for (int i = 0; i < len - k + 1; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && k == 2) {
                return 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][len - 1];
}
