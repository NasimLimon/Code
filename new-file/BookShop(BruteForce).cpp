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
ll dp[1000 + 2][100000 + 2];
vector<ll> prices;
vector<ll> pages;
ll n, x;
ll BookShop(ll index, ll maxPrice)
{
    if (maxPrice == 0)
        return 0;

    if (index < 0)
        return 0;
    if (dp[index][maxPrice] != -1)
        return dp[index][maxPrice];
    ll ans;
    ans = BookShop(index - 1, maxPrice);
    if (maxPrice - prices[index] >= 0)
        ans = max(ans, BookShop(index - 1, maxPrice - prices[index]) + pages[index]);
    dp[index][maxPrice] = ans;
    return ans;
}
int main()
{
    Limon();

    cin >> n >> x;
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        prices.push_back(x);
    }
    for (ll i = 1; i <= n; i++)
    {
        ll xx;
        cin >> xx;
        pages.push_back(xx);
    }
    cout << BookShop(n - 1, x) << endl;
}