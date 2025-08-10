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
vector<ll> val;
vector<ll> wt;
ll dp[105][100005];
ll Knapsack2(ll index, ll value_left)
{
    if (value_left == 0)
        return 0;
    if (index < 0)
        return 1e15;
    if (dp[index][value_left] != -1)
        return dp[index][value_left];
    ll skiping = Knapsack2(index - 1, value_left);
    ll picking;
    if (value_left - val[index] >= 0)
    {
        picking = Knapsack2(index - 1, value_left - val[index]) + wt[index];
    }
    ll ans = min(skiping, picking);
    dp[index][value_left] = ans;
    return ans;
}
int main()
{
    Limon();
    ll n, targetWeight;
    cin >> n >> targetWeight;
    memset(dp, -1, sizeof(dp));
    ll mxValue = 0;
    for (int i = 1; i <= n; i++)
    {
        ll w, v;
        cin >> w >> v;
        val.push_back(v);
        wt.push_back(w);
        mxValue += v;
    }

    for (ll i = mxValue; i >= 0; i--)
    {
        ll minWeight = Knapsack2(n - 1, i);
        if (minWeight <= targetWeight)
        {
            cout << i << endl;
            break;
        }
    }
}