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
ll dp[105][100005];
vector<ll> v1;

ll funcCount(ll index, ll sum)
{

    if (sum == 0)
        return 1;
    if (index < 0)
        return 0;
    if (sum < 0)
        return 0;
    if (dp[index][sum] != -1)
        return dp[index][sum];
    ll ans = 0;

    ans += funcCount(index, sum - v1[index]);
    ans += funcCount(index - 1, sum);
    ans %= MOD;
    dp[index][sum] = ans;
    return ans;
}
int main()
{
    Limon();
    ll n, target;
    cin >> n >> target;
    memset(dp, -1, sizeof(dp));

    for (ll i = 0; i < n; i++)
    {
        ll w;
        cin >> w;
        v1.push_back(w);
    }
    cout << funcCount(n - 1, target) << endl;
}