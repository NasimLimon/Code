//                                           IN THE NAME OF SUPREME & MERCIFUL GOD
//                                               Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int mx = 1e5;
vector<pair<int, int>> adj[mx];
vector<long long> dist(mx);
vector<long long> parent(mx);
vector<long long> x;
long long shortestDis = -1;
long long node, check;
void dijstra(int start)
{
    for (int i = 1; i <= node; i++)
    {

        dist[i] = infLL;
        parent[i] = -1;
    }
    dist[start] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        long long cuN = pq.top().second;
        long long cuD = pq.top().first;
        pq.pop();
        if (cuD > dist[cuN])
            continue;
        for (auto x : adj[cuN])
        {
            if (cuD + x.second < dist[x.first])
            {
                dist[x.first] = cuD + x.second;
                parent[x.first] = cuN;
                shortestDis = max(dist[x.first], shortestDis);
                pq.push({dist[x.first], x.first});
            }
            if (shortestDis == dist[x.first])
            {
                check = x.first;
            }
        }
    }
}

int main()
{
    optimize();

    cin >> node;
    for (int i = 1; i <= node; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijstra(1);
    cout << shortestDis << endl;
    cout << check << endl;
    while (check != -1)
    {
        x.push_back(check);
        check = parent[check];
    }
    reverse(x.begin(), x.end());
    for (auto m : x)
    {
        cout << m << " ";
    }

    return 0;
}
