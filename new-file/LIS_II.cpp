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
ll dp[100005];
vector<ll> v1;

ll funct(ll index)
{
    if (dp[index] != -1)
        return dp[index];
    ll ans = 1;
    for (int i = 0; i < index; i++)
    {
        if (v1[index] > v1[i])
        {
            ans = max(ans, funct(i) + 1);
        }
    }
    dp[index] = ans;
    return ans;
}
int main()
{
    Limon();
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        ll we;
        cin >> we;
        v1.push_back(we);
    }
    ll ans = 0;
    for (int i = 0; i <n; i++)
    {
        ans = max(ans, funct(i));
    }
    cout << ans << endl;
}