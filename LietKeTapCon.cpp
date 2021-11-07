#include <bits/stdc++.h>
using namespace std;

int a[100], n, k;
vector<string> res;
string s;

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            string tmp = "";
            for (int l = 1; l <= n; l++)
            {
                if (a[l] == 1)
                    tmp = tmp + s[l - 1];
            }    
            if (tmp != "")
                res.push_back(tmp);
        }
        else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        res.clear();
        Try(1);
        sort(res.begin(), res.end());

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}