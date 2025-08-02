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
#define Limon()                   \
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
ll vis[1000000 + 5];
ll dp[1000000 + 5];
vector<ll> v1;
ll sum(int w)
{
    if (vis[w] == 1)
        return dp[w];
    if (w == 0)
        return 0;
    ll res;
    for (auto q : v1)
    {
        if (w - q >= 0)
        {
            res = sum(w - q) + 1;
            dp[w] = min(res, dp[w]);
        }
    }
    vis[w] = 1;
    return dp[w];
}
int main()
{
    Limon();
    ll n, x;
    cin >> n >> x;
    for (int i = 0; i <= x; i++)
    {
        vis[i] = 0;
        dp[i] = INT_MAX;
    }

    for (int i = 1; i <= n; i++)
    {
        ll x1;
        cin >> x1;
        v1.push_back(x1);
    }
    ll ans = sum(x);
    if (dp[x] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
