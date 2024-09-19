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
const int mx = 1e3 + 10;
int arr[mx][mx];
int vis[mx][mx];
int n;

void dfs(int s, int t)
{
    vis[s][t] = 2;
    for (int i = 0; i < 8; i++)
    {
        int x1 = s + dx[i];
        int y1 = t + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && arr[x1][y1] != 1 && vis[x1][y1]!=2)
        {
            dfs(x1, y1);
        }
    }
}
int main()
{
    optimize();
    int a, b, c, d, e, f;
    cin >> n;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = 1; i <= n; i++)
    {
        arr[i][b] = 1;
        arr[a][i] = 1;
    }
    int i = a;
    int j = b;
    while (i >= 1 && j <= n)
    {
        i--;
        j++;
        arr[i][j] = 1;
    }
     i = a;
     j = b;
    while (i <= n && j >= 1)
    {
        i++;
        j--;
        arr[i][j] = 1;
    }
     i = a;
     j = b;
    while (i <= n && j <= n)
    {
        i++;
        j++;
        arr[i][j] = 1;
    }
     i = a;
     j = b;
    while (i >= 1 && j >= 1)
    {
        i--;
        j--;
        arr[i][j] = 1;
    }
    dfs(c, d);
    if (vis[e][f] == 2)
        cout << "YES" << endl;
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}