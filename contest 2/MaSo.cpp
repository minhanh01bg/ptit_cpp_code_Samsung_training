#include <bits/stdc++.h>
using namespace std;
bool check[6];
int n, a[6];
char S[7] = {' ', 'A', 'B', 'C', 'D', 'E', 'F'};

void init()
{
    for (int i = 1; i <= n; i++)
    {
        check[i] = false;
    }
}
int b[3125], cnt = 0;
string s[120];
int cnt1 = 0;
void res1()
{
    for (int i = 1; i <= n; i++)
        b[cnt] = b[cnt] * 10 + a[i];
    cnt += 1;
}

void res()
{
    for (int i = 1; i <= n; i++)
    {
        s[cnt1] += S[a[i]];
    }
    cnt1 += 1;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (!check[j])
        {
            a[i] = j;
            check[j] = true;
            if (i == n)
            {
                res();
            }
            else
                Try(i + 1);
            check[j] = false;
        }
    }
}

void Try1(int i)
{
    for (int j = 1; j <= n; j++)
    {
        a[i] = j;
        if (i == n)
            res1();
        else
            Try1(i + 1);
    }
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    init();
    cin >> n;
    Try(1);
    init();
    Try1(1);
    for (int i = 0; i < cnt1; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            cout << s[i] << b[j] << endl;
        }
    }
    return 0;
}