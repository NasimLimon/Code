// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
struct info
{
    int u, v, w;
};
vector<info> e;
const int mx = 1000 + 10;
int dist[mx];
int par[mx];
vector<int> adj[mx];
vector<int> vis(mx);
void dfs(int source)
{
    vis[source] = 1;
    for (auto x : adj[source])
    {
        if (vis[x] == 0)
        {
            dfs(x);
        }
    }
}
vector<int> bellmanford(int source, int node, int edge)
{
    vector<int> path;
    path.clear();

    for (int i = 0; i < node; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;
    int x = -1;
    for (int i = 1; i <= node; i++)
    {
        x = -1;
        for (int j = 0; j < edge; j++)
        {
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;
            if (dist[u] < INT_MAX)
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    x = v;
                }
            }
        }
    }
    if (x == -1)
        return path;
    for (int i = 1; i <= node; i++)
    {
        x = par[x];
    }
    int y = x;
    do
    {
        path.push_back(y);
        y = par[y];

    } while (y != x);

    sort(path.begin(), path.end());
    return path;
}
int main()
{
    optimize();
    int tc, t;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        e.clear();
        for (int i = 0; i < mx; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        cout << endl;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e.push_back({u, v, w});
            adj[v].push_back(u);
        }
        vector<int> ans = bellmanford(0, n, m);
        if (ans.empty())
            cout << "case " << t << ": " << "impossible " << endl;
        else
        {

            for (auto f : ans)
            {
                dfs(f);
            }
            vector<int> viss;
            for (int i = 0; i < vis.size(); i++)
            {
                if (vis[i] == 1)
                {
                    viss.push_back(i);
                }
            }
            sort(viss.begin(), viss.end());
            cout << "case " << t << ": ";

            for (int i = 0; i < viss.size(); i++)
            {
                // if (vis[i] == 1)
                {
                    cout << viss[i] << " ";
                }
            }
            //cout << endl;
        }
    }
    return 0;
}