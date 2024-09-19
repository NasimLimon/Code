// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int mx = 2e5 + 10;
vector<int> v[mx];
bool vis[mx];
vector<int> q;
void dfs(int start)
{
    vis[start] = 1;
    q.push_back(start);
    for (auto x : v[start])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    optimize();
    int m;
    cin >> m;
    for (int i = 2; i <= m; i++)
    {
        int x;
        cin >> x;
        v[i].push_back(x);
    }
    dfs(m);
    for (int i = q.size() - 1; i >= 0; i--)
    {
        cout << q[i] << " ";
    }
}