#include <bits/stdc++.h>
using namespace std;

struct Cv
{
    int pre;
    int pos;
};

bool cmp(Cv a, Cv b)
{
    if (a.pos < b.pos)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<Cv> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].pre;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].pos;
        }
        sort(a.begin(), a.end(), cmp);
        int dem = 1, j; //(1-2)
                        //	1  3  0  5  8  5
                        //	2  4  6  7  9  9
        j = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[j].pos <= a[i].pre)
            {
                dem++;
                j = i;
            }
        }
        cout << dem;
        cout << endl;
    }
    return 0;
}