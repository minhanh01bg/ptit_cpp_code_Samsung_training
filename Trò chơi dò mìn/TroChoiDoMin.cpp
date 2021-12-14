#include <bits/stdc++.h>
using namespace std;
namespace Acc
{
    using ll = long long;
    const int N = 1e6 + 10, mod = 1e9 + 7;
    ll f[N][5], n, i, j;
    // 0 for 0
    // 1 for 1-l
    // 2 for 1-r
    // 3 for 2
    // 4 for *
    char s[N];
    void work()
    {
        cin >> s + 1, n = strlen(s + 1), f[0][0] = f[0][2] = 1;
        for (i = 1; i <= n; i++)
        {
            j = s[i] == '?';
            if (j || s[i] == '0')
                f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
            if (j || s[i] == '1')
                f[i][1] = f[i - 1][4], f[i][2] = f[i - 1][0] + f[i - 1][1];
            if (j || s[i] == '2')
                f[i][3] = f[i - 1][4];
            if (j || s[i] == '*')
                f[i][4] = (f[i - 1][2] + f[i - 1][3] + f[i - 1][4]) % mod;
        }
        cout << (f[n][0] + f[n][1] + f[n][4]) % mod << '\n';
    }
}
int main()
{
    return Acc::work(), 0;
}
