// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int main()
{
    optimize();
    int m, n;
    cin >> m >> n;
    char grid[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'S')
            {
                int x = i;
                int y = j;
                for (int k = 0; k < 4; k++)
                {
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] == 'W')
                    {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                grid[i][j] = 'D';
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
}