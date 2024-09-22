// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int mx = 1e5 + 10;
long long a[mx];
vector<int> adj[mx];
int visited[mx];
long long ans;
long long final = 0;
void dfs(int start)
{
    visited[start] = 1;
    ans = min(ans, a[start]);
    for (auto x : adj[start])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    optimize();
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= n; k++)
    {
        visited[k] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            ans = 1e18;
            dfs(i);
            final = final + ans;
        }
    }
    cout << final << endl;
    return 0;
}