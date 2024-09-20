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
const int mx = 105;
char adj[mx][mx];
int n, m;
int vis[mx][mx];

void dfs(int star1, int star2)
{
    vis[star1][star2]=1;
    if (adj[star1][star2] == '.')
    {
        adj[star1][star2] = 'B';
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = star1 + dx[i];
        int y1 = star2 + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && adj[x1][y1] != '-' && vis[x1][y1]==0)
        {
            vis[x1][y1]=1;
            if (adj[star1][star2] == 'B')
            {
                adj[x1][y1] = 'W';
            }
            else
            {
                adj[x1][y1] = 'B';
            }
            dfs(x1, y1);
        }
    }
}
int main()
{
    optimize();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
             vis[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (adj[i][j] == '.'&& vis[i][j]==0)
            {
                dfs(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }
}
