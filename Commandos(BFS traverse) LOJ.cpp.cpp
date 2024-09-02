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
#define optimize()              \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

const int mx = 105; // 100 nodes are given in the problem
vector<int> adj[mx];
int dist_s[mx], dist_d[mx];
bool vis[mx];

void bfs(int start, int dist[])
{
    memset(vis, 0, sizeof(vis)); // Reset visited array
    queue<int> q;
    vis[start] = 1;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (auto x : adj[p])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                dist[x] = dist[p] + 1;
                q.push(x);
            }
        }
    }
}

int main()
{
    optimize();
    int tc;
    cin >> tc;

    for (int f = 1; f <= tc; f++)
    {
        int node, edge;
        cin >> node >> edge;

        // Clear adjacency list and distance arrays for each test case
        for (int i = 0; i < node; i++)
        {
            adj[i].clear();
            dist_s[i] = dist_d[i] = 0;
        }

        for (int i = 0; i < edge; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int s, t;
        cin >> s >> t;

        // BFS from the starting point
        bfs(s, dist_s);

        // BFS from the destination point
        bfs(t, dist_d);

        // Calculate the maximum time needed for any commando
        int ans = 0;
        for (int i = 0; i < node; i++)
        {
            ans = max(ans, dist_s[i] + dist_d[i]);
        }

        // Print the result for the current test case
        cout << "Case " << f << ": " << ans << endl;
    }

    return 0;
}
