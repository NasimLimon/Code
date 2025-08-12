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

int main()
{
    Limon();
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size();
    ll m = s2.size();
    float dp[n + 2][m + 2];
    set<char> v;
    set<char> c;
    v.insert('A');
    v.insert('E');
    v.insert('I');
    v.insert('O');
    v.insert('U');

    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (v.find(i) != v.end())
            continue;
        c.insert(i);
    }
    for (ll i = 0; i <= s2.size(); i++)
    {
        dp[0][i] = i;
    }
    for (ll i = 1; i <= s1.size(); i++)
    {
        dp[i][0] = i;
    }
    for (ll i = 1; i <= s1.size(); i++)
    {
        for (ll j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                //  char x1 = s1[i - 1];
                // char x2 = s2[i - 1];
                // if ((v.find(x1) != v.end()) && (v.find(x2) != v.end()))
                {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]) + 1;
                }
                /*
                 if ((v.find(x1) != v.end()) && (c.find(x2) != c.end()) || (v.find(x2) != v.end()) && (c.find(x1) != c.end()))
                 {
                     dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1]);
                     dp[i][j] = min(dp[i][j], dp[i - 1][j]) + 2;
                 }
                 if ((c.find(x1) != c.end()) && (c.find(x2) != c.end()))
                 {
                     dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1]);
                     dp[i][j] = min(dp[i][j], dp[i - 1][j]) + 1;
                 }*/
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;
}
