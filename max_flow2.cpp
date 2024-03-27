#include<bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int INF = 1e9;

int cap[MAXN][MAXN];
int pr[MAXN];

int bfs(int s, int t, int n)
{
    memset(pr, -1, sizeof(pr));
    queue<int> q;
    q.push(s);
    pr[s] = -2;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (pr[v] == -1 && cap[u][v] > 0)
            {
                pr[v] = u;
                if (v == t) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t, int n)
{
    int flow = 0;
    while (bfs(s, t, n))
    {
        int f = INF;
        for (int v = t; v != s; v = pr[v])
        {
            int u = pr[v];
            f = min(f, cap[u][v]);
        }

        for (int v = t; v != s; v = pr[v])
        {
            int u = pr[v];
            cap[u][v] -= f;
            cap[v][u] += f;
        }

        flow += f;
    }
    return flow;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        memset(cap, 0, sizeof(cap));

        int n, m, s, t;
        scanf("%d %d %d %d", &n, &s, &t, &m);

        while (m--)
        {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            cap[u][v] += c;
            cap[v][u] += c;
        }

        int maxflow = maxFlow(s, t, n);

        printf("Case %d: %d\n", tc, maxflow);
    }

    return 0;
}
