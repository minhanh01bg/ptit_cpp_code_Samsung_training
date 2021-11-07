#include <bits/stdc++.h>
#define int long long
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

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int findInd(vector<pair<int, int>> &preSum, int n, int val)
{
    int l = 0;
    int h = n - 1;
    int mid;
    int ans = -1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (preSum[mid].first <= val)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return ans;
}

int Longest(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] -= x;
    int maxlen = 0;
    vector<pair<int, int>> preSum;
    int sum = 0;
    int minInd[n];
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        preSum.push_back({sum, i});
    }
    sort(preSum.begin(), preSum.end(), compare);
    minInd[0] = preSum[0].second;
    for (i = 1; i < n; i++)
    {
        minInd[i] = min(minInd[i - 1], preSum[i].second);
    }
    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum >= 0)
            maxlen = i + 1;
        else
        {
            int ind = findInd(preSum, n, sum);
            if (ind != -1 && minInd[ind] < i)
                maxlen = max(maxlen, i - minInd[ind]);
        }
    }
    return maxlen;
}

signed main()
{
    int n, x;
    cin >> n >> x;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Longest(arr, n, x);
    return 0;
}