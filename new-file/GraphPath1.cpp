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
ll dp[1000 + 2][1000 + 2];

char arr[1000 + 2][1000 + 2];
set<pair<ll, ll>> s1;
ll n;
ll GridPath1(ll i, ll j)
{
    if (i == j && n == i)
        return 1;
    if (i > n || j > n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    if (arr[i][j + 1] != '*')
        ans += GridPath1(i, j + 1);
    if (arr[i + 1][j] != '*')
        ans += GridPath1(i + 1, j);
    ans = ans % MOD;
    dp[i][j] = ans;
    return ans;
}
int main()
{
    Limon();

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (arr[1][1] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 && arr[1][1] == '.')
    {
        cout << 1 << endl;
        return 0;
    }

    cout << GridPath1(1, 1) << endl;
}