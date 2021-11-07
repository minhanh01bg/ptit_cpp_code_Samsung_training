#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[35], b, n, k, ans = 100;
map<ll, ll> M;
void Try1(ll idx, ll sum, ll cnt)
{
    if (sum > b)
        return;
    if (idx == k)
    {
        if (!M[sum])
            M[sum] = cnt;
        else
            M[sum] = min(cnt, M[sum]);
        return;
    }
    Try1(idx + 1, sum, cnt);
    Try1(idx + 1, sum + a[idx], cnt + 1);
}

void Try2(ll idx, ll sum, ll cnt)
{
    if (sum > b)
        return;
    if (idx == n)
    {
        if (sum == b)
            ans = min(ans, cnt);
        else if (M[b - sum])
            ans = min(ans, M[b - sum] + cnt);
        return;
    }
    Try2(idx + 1, sum, cnt);
    Try2(idx + 1, sum + a[idx], cnt + 1);
}

void process()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = n / 2;
    Try1(0, 0, 0);
    Try2(k, 0, 0);
    if (ans == 100)
        cout << -1;
    else
        cout << ans;
}
signed main()
{
    process();
}