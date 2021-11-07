#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    a[n] = 1e9;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i] - a[i + 1]) > k)
        {
            cnt += 1;
        }
    }
    cout << cnt;
}