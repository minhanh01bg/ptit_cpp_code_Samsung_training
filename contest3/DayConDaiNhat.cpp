#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define run() \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;

/*____________________________________MY CODE__________________________________*/

void process()
{
    int n;
    cin >> n;
    pair<double, double> a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    int dp[n + 1];
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j].first < a[i].first && a[j].second > a[i].second && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    cout << *max_element(dp + 1, dp + n + 1) << endl;
}

signed main()
{
    faster()
        run()
            process();
}