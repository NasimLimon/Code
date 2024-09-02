//In the name of Supreme God
//https://lightoj.com/problem/best-picnic-ever
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
#define mem(a, b) memset(a, b, sizeof(a))
#define sqr(a) ((a) * (a))
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

const int mx = 1e4 + 10;
bool vis[mx];
int sum[mx];
vector<int> adj[mx];
set<int> Q;
int K, M, N;

void bfs(int start)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[start] = 1;
    ++sum[start];
    q.push(start);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (auto v : adj[p])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                ++sum[v];
                q.push(v);
            }
        }
    }
}

int main()
{
    optimize();
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cin >> K >> M >> N;

        Q.clear();
        for (int i = 1; i <= M; i++)
        {
            adj[i].clear();
            sum[i] = 0;
        }

        while (K--)
        {
            int x;
            cin >> x;
            Q.insert(x);
        }

        for (int i = 1; i <= N; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (auto it = Q.begin(); it != Q.end(); it++)
        {
            bfs(*it);
        }

        int count = 0;
        for (int i = 1; i <= M; i++)
        {
            if (sum[i] ==Q.size())
            {
                count++;
            }
        }

        cout << "Case " << t << ": " << count << endl;
    }

    return 0;
}