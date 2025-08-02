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
int dp[1000000 + 5];
int vis[1000000 + 5];
int sum(int w)
{
    if (vis[w] == 1)
        return dp[w];
    if (w == 0)
        return 1;
    int res = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (w >= i)
        {
            res += sum(w - i);
            res = res % MOD;
        }
    }
    dp[w] = res;
    vis[w] = 1;
    return res;
}
int main()
{
    optimize();
    ll n;
    cin >> n;
    int x = sum(n);
    cout << x << endl;
}
Share code to others
Test details
Test 1
