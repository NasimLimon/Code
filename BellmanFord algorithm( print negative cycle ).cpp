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
const int mx = 2502;
vector<info> e;
long long dist[mx];
int par[mx];

vector<int> bellmanFord(int source, int node, int edge)
{
    vector<int> path;
    for (int i = 1; i <= node; i++)
        dist[i] = LLONG_MAX;
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
            if (dist[u] < LLONG_MAX && dist[u] + w < dist[v])  // Ensure no overflow
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
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
    while (y != x || path.size() == 0)
    {
        path.push_back(y);
        y = par[y];
    }
    path.push_back(x);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    optimize();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    vector<int> ans = bellmanFord(1, n, m);

    if (sizeof(ans)==0)  // Correct check for empty vector
        cout << "NO CYCLE PATH";
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;  // Adding an extra newline for formatting
    }
}
