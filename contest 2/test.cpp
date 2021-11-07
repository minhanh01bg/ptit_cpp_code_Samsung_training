#include <bits/stdc++.h>
using namespace std;

bool check[10];
int n;
int a[10];
string s[10];
int k;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        check[i] = false;
    }
}

int Min = INT_MAX;
int val(string str)
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
        res = res * 10 + (str[i] - '0');
    return res;
}

void res()
{
    int xy[10];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string st = "";
        for (int j = 1; j <= k; j++)
        {
            st += s[i][a[j]];
        }
        xy[cnt] = val(st);
        cnt += 1;
    }
    sort(xy, xy + cnt);
    // for (int i = 0; i < cnt; i++)
    // {
        // cout << xy[i] << " ";
    // }
    Min = min(Min, abs(xy[0] - xy[cnt - 1]));
}

void Try(int i)
{
    for (int j = 1; j <= k; j++)
    {
        if (check[j] == false)
        {
            check[j] = true;
            a[i] = j;
            if (i == k)
                res();
            else
                Try(i + 1);
            check[j] = false;
        }
    }
}

int main()
{
    init();
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    Try(1);
    cout << Min << endl;
}