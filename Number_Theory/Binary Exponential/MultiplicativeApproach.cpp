
// BinaryMultiplication
ll BinaryMultiplication(ll a, ll b)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % MOD;
        }
        a = (a + a) % MOD;
        b = b >> 1;
    }
    return ans;
}
// Iterative approach
ll BinaryIter(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = BinaryMultiplication(ans, a);
        }
        a = BinaryMultiplication(a, a);
        b = b >> 1;
    }
    return ans;
}

int main()
{
    optimize();
    ll n, m;
    cin >> n >> m;
    cout << BinaryIter(n, m) << endl;
}

