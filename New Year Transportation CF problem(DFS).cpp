// IN THE NAME OF SUPREME & MERCIFUL GOD
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
const int mx = 1e5 + 10;
vector<int> v[mx];
int vis[mx];

void dfs(int source)
{
	vis[source] = 1;
	for (auto r : v[source])
	{
		if (!vis[r])
		{
			vis[r] = 1;
			dfs(r);
		}
	}
}
int main()
{
	int n, t;
	cin >> n >> t;
	// int v[n - 1];

	for (int i = 1; i <= n - 1; i++)
	{
		int u;
		cin >> u;
		v[i].push_back(i);
		v[i].push_back(i + u);
	}
	dfs(1);
	if (vis[t] == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}