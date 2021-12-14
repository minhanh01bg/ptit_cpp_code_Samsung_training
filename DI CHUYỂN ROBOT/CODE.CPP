#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void dfs(int x, int y, int i, string token)
{
    if (i == n + 1)
    {
        cout << x << " " << y;
        return;
    }
    if (s[i] == 'G')
    {
        if (token == "front")
            dfs(x, y + 1, i + 1, "front");
        else if (token == "back")
        {
            dfs(x, y - 1, i + 1, "back");
        }
        else if (token == "left")
        {
            dfs(x - 1, y, i + 1, "left");
        }
        else
        {
            dfs(x + 1, y, i + 1, "right");
        }
    }
    else if (s[i] == 'L')
    {
        if (token == "front")
            dfs(x - 1, y, i + 1, "left");
        else if (token == "back")
        {
            dfs(x + 1, y, i + 1, "right");
        }
        else if (token == "left")
        {
            dfs(x, y - 1, i + 1, "back");
        }
        else
        {
            dfs(x, y + 1, i + 1, "front");
        }
    }
    else if (s[i] == 'R')
    {
        if (token == "front")
            dfs(x + 1, y, i + 1, "right");
        else if (token == "back")
        {
            dfs(x - 1, y, i + 1, "left");
        }
        else if (token == "left")
        {
            dfs(x, y + 1, i + 1, "front");
        }
        else
        {
            dfs(x, y - 1, i + 1, "back");
        }
    }
    else // B
    {
        if (token == "front")
            dfs(x, y - 1, i + 1, "back");
        else if (token == "back")
        {
            dfs(x, y + 1, i + 1, "front");
        }
        else if (token == "right")
        {
            dfs(x - 1, y, i + 1, "left");
        }
        else
        {
            dfs(x + 1, y, i + 1, "right");
        }
    }
}
void process()
{
    cin >> n >> s;
    s = " " + s;
    dfs(0, 0, 1, "front");
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    process();
}