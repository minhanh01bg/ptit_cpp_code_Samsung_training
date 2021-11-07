#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        long long maxres = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long lis[n];
        for (int i = 0; i < n; i++)
        {
            lis[i] = a[i];
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                {
                    lis[i] = max(lis[i], lis[j] + a[i]);
                }
            }
            maxres = max(maxres, lis[i]);
        }
        cout << maxres;
        cout << endl;
    }
    return 0;
}