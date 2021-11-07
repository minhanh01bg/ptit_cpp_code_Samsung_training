#include <bits/stdc++.h>
using namespace std;
bool dp[1001][1001];
int n, m;
char a[1001][1001];
void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            dp[i][j] = false;
}
bool check(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m || a[i][j] == '.')
        return false; //
    return true;
}
int dX[4] = {0, 1, 0, -1};
int dY[4] = {1, 0, -1, 0};

void dfs(int i, int j)
{
    dp[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dX[k], y = j + dY[k];
        if (check(x, y) && dp[x][y] == false)
        {
            dfs(x, y);
        }
    }
}

void process()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '#' && dp[i][j] == false)
            {
                cnt += 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
}
signed main()
{
    init();
    process();
}
/*
5 6
.#....
.##...
..#..#
...##.
.#....
*/