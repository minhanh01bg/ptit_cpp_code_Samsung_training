#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = power(a, b / 2) % mod;
    return (b & 1) ? (((t * t) % mod) * a) % mod : (t * t) % mod;
}

signed main()
{
    ll a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << power(a, b) << endl;
    }
}