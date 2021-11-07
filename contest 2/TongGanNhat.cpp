#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++)
                {
                    if (k == j || k == i)
                        continue;
                    if (a[i] + a[j] + a[k] <= m && a[i] + a[j] + a[k] > ans)
                    {
                        ans = a[i] + a[j] + a[k];
                        // cout << a[i] << " " << a[j] << " " << a[k] << '\n';
                    }
                }
            }
        }
        cout << ans << endl;
    }
}