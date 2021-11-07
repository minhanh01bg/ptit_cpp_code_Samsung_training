#include <bits/stdc++.h>
using namespace std;
void mmi(vector<int> a, int n, int k)
{
    int i = 0;
    deque<int> Qi(k);
    for (; i < k; i++)
    {
        while (!Qi.empty() && a[i] >= a[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < n; i++)
    {
        cout << a[Qi.front()] << " ";
        while (!Qi.empty() && Qi.front() <= i - k)
            Qi.pop_front();
        while (!Qi.empty() && a[i] >= a[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << a[Qi.front()] << endl;
}
int mi()
{
    int t;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        mmi(a, n, k);
    }
    return 0;
}
int main()
{
    mi();
}