#include<bits/stdc++.h>
using namespace std;

int m;
int coin[55];
long long dp[55][55];

long long coinChange(int i,int n)
{
    if(n == 0) return 1;
    if(i == m or n < 0) return 0;
    if(dp[i][n] != -1) return dp[i][n];
    dp[i][n] = coinChange(i + 1, n) + coinChange(i,n - coin[i]);
    return dp[i][n];
}
int main()
{    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> coin[i];

    cout << coinChange(0,n);
}
