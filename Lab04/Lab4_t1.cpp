#include <iostream>

using namespace std;
int count=0;
int adj[1000][1000]={0};
bool visited[100];
void available(int src,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(adj[src][i]==1 && !visited[i])
        {
            visited[i]=1;
            count++;
            available(i, n);
        }
    }
}

int main()
{
    int n, m;
    int inaccessible;
    cin >> n >> m;

    for(int k=0;k<m;k++)
    {
        int i, j;
        cin >> i >> j;
        adj[i][j] = 1;
    }
    int p, q;
    cin >> p;
    for(int k=0;k<p;k++)
    {
        visited[n]={false};
        cin >> q;
        available(q, n);
        inaccessible=n-count;
        cout << inaccessible << " ";
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

}
