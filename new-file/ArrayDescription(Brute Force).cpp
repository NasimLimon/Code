// IN THE NAME OF SUPREME & MERCIFUL GOD
// Bismillahir Rahmanir Rahim
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

ll n, m;
vector<ll> v1;
ll dp[100005][100 + 2];
ll ArrayDescription(ll index, ll prev)
{
    if (index == n)
        return 1;
    if (dp[index][prev] != -1)
    {
        return dp[index][prev];
    }
    ll ans = 0;

    if (v1[index] != 0)
    {

        if (v1[index] != 0 && index != 0)
        {
            if (abs(prev - v1[index]) < 2)
            {
                ans = (ans + ArrayDescription(index + 1, v1[index])) % MOD;
            }
        }
        if (v1[index] != 0 && index == 0)
        {

            {
                ans = (ans + ArrayDescription(index + 1, v1[index])) % MOD;
            }
        }
    }
    else
    {
        if (v1[index] == 0 && index == 0)
        {
            for (ll i = 1; i <= m; i++)
            {
                ans = (ans + ArrayDescription(index + 1, i)) % MOD;
            }
        }
        else
        {
            ll lo = max(1LL, prev - 1);
            ll hi = min(m, prev + 1);
            for (ll val = lo; val <= hi; ++val)
            {
                ans = (ans + ArrayDescription(index + 1, val)) % MOD;
            }
        }
    }
    dp[index][prev] = ans;
    return ans;
}

int main()
{
    Limon();

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v1.push_back(x);
    }

    cout << ArrayDescription(0, 0) << endl;
}
