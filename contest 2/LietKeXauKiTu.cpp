#include <bits/stdc++.h>
using namespace std;

int a[100], n, k;
vector<string> res;

bool check1()
{
    for (int l = 1; l < k; l++)
    {
        if (a[l] > a[l + 1])
            return false;
    }
    return true;
}

void up()
{
    if (check1())
    {
        string str = "";
        for (int l = 1; l <= k; l++)
        {
            str += (char)(a[l] + 64);
        }
        res.push_back(str);
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        a[i] = j;
        if (i == k)
        {
            up();
        }
        else
            Try(i + 1);
    }
}

int main()
{
    char c;
    cin >> c >> k;
    n = c - 64;
    Try(1);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}