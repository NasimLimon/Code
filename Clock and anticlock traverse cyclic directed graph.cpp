///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///
//https://lightoj.com/problem/one-way-roads
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

int n, ans1, ans2;
const int mx = 1005;
vector<int> adj[mx];
map<pair<int, int>, int> mp;

void clockwise()
{
  int cur_city = 1;
  int next_city = adj[1][0];
  ans1 = 0;
  for (int j = 1; j <= n; j++)
  {
    ans1 += mp[{cur_city, next_city}];
    int temp = adj[next_city][0];
    if (temp == cur_city)
    {
      temp = adj[next_city][1];
    }
    cur_city = next_city;
    next_city = temp;
  }
}

void anti_clock()
{
  int cur_city = 1;
  int next_city = adj[1][1];
  ans2 = 0;
  for (int j = 1; j <= n; j++)
  {
    ans2 += mp[{cur_city, next_city}];
    int temp = adj[next_city][0];
    if (temp == cur_city)
    {
      temp = adj[next_city][1];
    }
    cur_city = next_city;
    next_city = temp;
  }
}

int main()
{
  optimize();
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++)
  {
    cin >> n;

    // Clear data structures for each test case
    for (int j = 1; j <= n; j++) adj[j].clear();
    mp.clear();

    // Input roads
    for (int j = 0; j < n; j++)
    {
      int u, v, w;
      cin >> u >> v >> w;
      mp[{u, v}] = w;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    // Solve both directions
    clockwise();
    anti_clock();

    // Output the result
    cout << "Case " << i << ": " << min(ans1, ans2) << endl;
  }

  return 0;
}
