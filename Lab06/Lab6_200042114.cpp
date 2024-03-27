#include <iostream>
using namespace std;
int a[20][20];
int n;
int dp[100000][20];

void reset()
{
    for(int i =0; i < 100000; i++)
    {
        for(int j = 0; j < 20; j++)
        dp[i][j] = -1;
    }
}

int func(long long int mask,int k)
{
    if (k==n)
    {
        return 0;
    }
    if (dp[mask][k] != -1)
    {
        return dp[mask][k];
    }
    int ans = 0;
    for (int i=0; i<n; i++)
    {
        if (mask & (1<<i))
        {
            continue;
        }
        ans = max(ans, a[k][i] + func((mask|1<<i), k+1));
    }
    dp[mask][k] = ans;
    return ans;
}

int main()
{
    cin >> n;
    reset();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    cout << func(0,0) << endl;
}
