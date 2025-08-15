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
ll dp[1005];
vector<ll> rodprices;
ll RodCutting(ll length_left)
{
    if (length_left == 0)
        return 0;
    if (dp[length_left] != -1)
        return dp[length_left];
    ll ans = 0;
    for (ll i = 1; i <= length_left; i++)
    {
        if (length_left - i >= 0)
        {
            ans = max(ans, RodCutting(length_left - i) + rodprices[i - 1]);
        }
    }
    dp[length_left] = ans;
    return ans;
}
int main()
{
    Limon();
    ll rodlength;
    cin >> rodlength;

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= rodlength; i++)
    {
        ll x;
        cin >> x;
        rodprices.push_back(x);
    }
    cout << RodCutting(rodlength) << endl;
}