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
ll arr[2] = {1, 2};
ll dp[35];
ll ClimbingStair(ll x)
{
    if (x == 0)
        return 1;
    if (dp[x] != -1)
        return dp[x];
    ll count = 0;
    for (int i = 0; i < 2; i++)
    {
        if (x - arr[i] >= 0)
        {
            count += ClimbingStair(x - arr[i]);
        }
    }
    dp[x] = count;
    return dp[x];
}
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < 35; i++)
    {
        dp[i] = -1;
    }
    cout << ClimbingStair(n) << endl;
}