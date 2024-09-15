/***from dust i have come, dust i will be***/

#include <bits/stdc++.h>
#define N 1100
using namespace std;

bool done;
int vis[N];
vector<int> adj[N];

void dfs(int s)
{
    if (done)
        return;

    vis[s] = 1;

    for (int e : adj[s])
    {
        if (!vis[e])
            dfs(e);
        else
        {
            cout << e << " ";
            done = true;
            return;
        }
    }
}

int main()
{
    int i, j, k;
    int n, m;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        adj[i].pb(m);
    }

    for (i = 1; i <= n; i++)
    {
        done = false;
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }

    return 0;
}