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

int main()
{
    Limon();
    ll n, x;
    cin >> n >> x;
    vector<ll> v1;
    for (int i = 1; i <= n; i++)
    {
        ll m;
        cin >> m;
        v1.push_back(m);
    }
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    // vector<vector<int>> dp(n + 1,vector<int>(x + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            ll skipped = dp[i + 1][sum];
            int picking = 0;
            if (v1[i] <= sum)
            {
                picking = dp[i][sum - v1[i]];
            }
            dp[i][sum] = (skipped + picking) % MOD;
        }
    }

    cout << dp[0][x] << endl;
}