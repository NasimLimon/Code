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

//https://leetcode.com/problems/partition-equal-subset-sum/description/
ll dp[505][505];
vector<ll> v1;

bool SubsetSum(ll index, ll sum)
{
    if (sum == 0)
        return 1;

    if (index < 0)
        return 0;
    if (dp[index][sum] != -1)
        return dp[index][sum];
    bool notTaken = SubsetSum(index - 1, sum);
    bool taken;
    if (sum - v1[index] >= 0)
    {
        taken = SubsetSum(index - 1, sum - v1[index]);
    }
    dp[index][sum] = notTaken || taken;
    return dp[index][sum];
}
int main()
{
    Limon();
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v1.push_back(x);
        sum += x;
    }
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    cout << SubsetSum(n - 1, sum / 2) << endl;
}