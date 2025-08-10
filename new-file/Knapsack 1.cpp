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
vector<ll> wt;
vector<ll> val;
ll dp[105][100005];
ll func(ll ind, ll wt_left)
{
    if (wt_left == 0)
        return 0;
    if (ind < 0)
        return 0;
    if (dp[ind][wt_left] != -1)
        return dp[ind][wt_left];
    ll ans1 = func(ind - 1, wt_left);
    ll ans2 = 0, ans;
    if (wt_left - wt[ind] >= 0)
    {
        ans2 = func(ind - 1, wt_left - wt[ind]) + val[ind];
    }
    ans = max(ans1, ans2);
    dp[ind][wt_left] = ans;
    return ans;
}
int main()
{
    Limon();
    ll n, weight;
    cin >> n >> weight;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        wt.push_back(a);
        val.push_back(b);
    }
    cout << func(n - 1, weight) << endl;
}
