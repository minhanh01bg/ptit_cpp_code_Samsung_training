#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
void process()
{
    int n;
    cin >> n;
    pair<int, int> A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i].first >> A[i].second;
    sort(A, A + n, compare);
    int cnt = 0;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i].first < last)
            continue;
        cnt += 1;
        last = A[i].second;
    }
    cout << cnt << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        process();
}