#include <bits/stdc++.h>

#define X first
#define Y second
#define pb push_back
#define EL printf("\n")
#define ll long long
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define faster()                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

/*____________________________________MY CODE______________________________*/
const int mod = 1e9 + 7;
ll power(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    ll t = power(a, b / 2) % mod;
    return (b & 1) ? ((t * t) % mod) * a % mod : (t * t) % mod;
}

int main()
{
    faster();
    while (true)
    {
        ll a, b;
        cin >> a >> b;
        if (a == 0 and b == 0)
            break;
        cout << power(a, b) << endl;
    }
}