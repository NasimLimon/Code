// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int xx = 1e3 + 5;
vector<int> adj[xx];
vector<bool> vis(xx);
bool done;
void dfs(int source)
{
    vis[source] = 1;
    for (auto e : adj[source])
    {
        if (!vis[e])
        {
            dfs(e);
        }
        else
        {
            cout << e << " ";
            return;
        }
    }
}
int main()
{
    optimize();
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int u;
        cin >> u;
        adj[i].push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {

        {
            for (int i = 1; i <= m; i++)
                vis[i] = 0;
        }
        dfs(i);
        }

    return 0;
}