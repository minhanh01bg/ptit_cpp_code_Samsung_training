#include <bits/stdc++.h>
using namespace std;
signed main()
{
// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
// #endif
//     srand(time(NULL));

    int C, n;
    cin >> C >> n;
    int a[n + 11];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dp[n + 11][C + 11];
    
    for (int i = 1; i <= C; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j < a[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << dp[n][C];
}