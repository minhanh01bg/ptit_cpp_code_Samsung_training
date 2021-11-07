#include <bits/stdc++.h>

#define pb push_back
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

/*____________________________________MY CODE______________________________*/
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
void process()
{
    int n;
    cin >> n;
    pair<int, int> a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = 0;
    int dp[n + 1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].second > a[i - 1].second)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
            dp[i] = 1;
    }
    cout << n - *max_element(dp + 1, dp + n + 1);
}

signed main()
{
    faster();
    process();
}