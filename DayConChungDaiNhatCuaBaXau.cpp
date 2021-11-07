#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n, m, p;
    string a, b, c;
    while (t--)
    {
        cin >> n >> m >> p;
        cin >> a >> b >> c;
        int d[n + 1][m + 1][p + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= p; k++)
                {
                    if (i == 0 || j == 0 || k == 0)
                        d[i][j][k] = 0;
                    else if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    {
                        d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                    }
                    else
                    {
                        d[i][j][k] = max(d[i][j - 1][k], max(d[i - 1][j][k], d[i][j][k - 1]));
                    }
                }
            }
        }
        cout << d[n][m][p];
        cout << endl;
    }
    return 0;
}