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
ll dp[505][505];
ll RectangleCutting(ll n, ll m)
{
    if (n == m && (n >= 1 && m >= 1))
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == 0 || m == 0)
        return 1e15;
    ll ans = 1e15, ans2, ans1;
    for (int i = 1; i <= n - 1; i++)
    {
        ans2 = RectangleCutting(n - i, m);
        ans1 = RectangleCutting(i, m);
        ans = min(ans, 1 + ans1 + ans2);
    }
    for (int i = 1; i <= m - 1; i++)
    {
        ans2 = RectangleCutting(n, m - i);
        ans1 = RectangleCutting(n, i);
        ans = min(ans, 1 + ans1 + ans2);
    }
    dp[n][m] = ans;
    return ans;
}
int main()
{
    Limon();
    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << RectangleCutting(a, b) << endl;
}