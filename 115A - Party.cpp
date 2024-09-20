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
const int mx = 2002;
int adj[mx];
int ans = 0;

int main()
{
    optimize();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        cin >> adj[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int total = 0;

        int v = adj[i];
        while (v != -1)
        {
            v = adj[v];
            total++;
        }
        ans = max(ans, total);
    }
    cout << ans + 1 << endl;
}