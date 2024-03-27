#include <iostream>
using namespace std;
int compatibility[20][20];
int n;
int dp[10000][20];

void set()
{
    for(int i =0; i < 10000; i++)
    {
        for(int j = 0; j < 20; j++)
        dp[i][j] = -1;
    }
}

int max_priority( int mask,int k)
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
        ans = max(ans, compatibility[k][i] + max_priority((mask|1<<i), k+1));
    }
    dp[mask][k] = ans;
    return ans;
}

int main()
{
    cin >> n;
    set();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> compatibility[i][j];
        }
    }
    cout << max_priority(0,0) << endl;
}
