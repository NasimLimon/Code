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
// ----------------- ADDED -----------------
int par[100005]; // parent pointer: previous index in LIS ending at i
// -----------------------------------------

ll funct(ll index)
{
    if (dp[index] != -1)
        return dp[index];
    ll ans = 1;
    par[index] = -1; // initialize parent for this index
    for (int i = 0; i < index; i++)
    {
        if (v1[index] > v1[i])
        {
            ll cand = funct(i) + 1;     // compute candidate length
            if (cand > ans)            // if better, update ans and parent
            {
                ans = cand;
                par[index] = i;
            }
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
    // initialize parent array to -1
    for (int i = 0; i < n; ++i) par[i] = -1;

    for (int i = 0; i < n; i++)
    {
        ll we;
        cin >> we;
        v1.push_back(we);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, funct(i));
    }
    cout << ans << endl;

    // ----- Reconstruct one LIS (follows parent pointers) -----
    // find an index that ends an LIS of length ans
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] == ans) { last = i; break; } // take first found
    }
    // build sequence backward
    vector<ll> seq;
    while (last != -1)
    {
        seq.push_back(v1[last]);
        last = par[last];
    }
    reverse(seq.begin(), seq.end());
    // print the LIS elements (on one line)
    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (i) cout << ' ';
        cout << seq[i];
    }
    cout << endl;

    return 0;
}

