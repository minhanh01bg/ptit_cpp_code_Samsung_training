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
const int MN = 1e6 + 7;
pair<int, int> A[MN];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}
void process()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i].first >> A[i].second;
    sort(A, A + n, cmp);
    int cnt = 0, last = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (last > A[i].first)
            continue;
        cnt += 1;
        last = A[i].second;
    }
    cout << cnt << endl;
}
signed main()
{
    faster();
    run()
    {
        process();
    }
}