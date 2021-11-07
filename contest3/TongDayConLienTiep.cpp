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

/*____________________________________MY CODE______________________________*/

int binarySearch(int arr[], int l, int n, int x)
{
    int r = n - 1;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            r = mid - 1;
        if (arr[mid] < x)
            l = mid + 1;
    }

    return -1;
}

void process()
{
    int n;
    cin >> n;
    int sum = 0;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int dp[n];
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
        dp[i] = dp[i - 1] + a[i];

    pair<int, int> b[n];
    int x = 0;
    for (int i = n; i >= 2; i--)
    {
        if (sum % i == 0)
        {
            b[x].first = sum / i;
            b[x].second = i;
            x++;
        }
    }
    // for (int i = 0; i < x; i++)
    // {
    // cout << b[i].first << " " << b[i].second << endl;
    // }
    // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    if (x == 0)
    {
        cout << sum << endl;
        return;
    }

    int ans = 0, check = 1;
    for (int i = 0; i < x; i++)
    {
        int cur = b[i].first;
        ans = b[i].second;
        int cnt = 0;
        int idx = 0;
        for (int i = 1; i <= ans; i++)
        {
            idx = binarySearch(dp, idx, n, cur * i);
            if (idx == -1)
                break;
            cnt += 1;
        }
        if (cnt == ans)
        {
            check = 0;
            ans = cur;
            break;
        }
    }
    if (check == 0)
        cout << ans << endl;
    else
        cout << dp[n - 1] << endl;
}

signed main()
{
    faster();
    run() process();
}