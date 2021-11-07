#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define ii pair<int, int>
#define iii map<int, int>

#define sz(A) (int)A.size()
#define all(c) (c).begin(), (c).end()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

#define run()     \
    int tests;    \
    cin >> tests; \
    cin.ignore(); \
    while (tests--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cout.tie(0);                      \
    cin.tie(0);
#define debug(a)     \
    FOR(i, 0, n - 1) \
    cout << a[i] << " \n"[i == n - 1];

#define INF 1000000000
#define N 10005
using namespace std;

int n, k;
int a[25], v[25];
vector<string> res;

bool check1(vector<int> x)
{
    for (int l = 0; l < x.size() - 1; l++)
    {
        if (x[l] > x[l + 1])
            return false;
    }
    return true;
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            int dem = 0;
            vector<int> x;
            for (int l = 1; l <= n; l++)
            {
                if (a[l] == 1)
                {
                    dem++;
                    x.push_back(v[l]);
                }
            }

            if (dem > 1 && check1(x))
            {
                string tmp = "";
                for (int l = 0; l < x.size(); l++)
                {
                    tmp = tmp + to_string(x[l]) + " ";
                }
                res.push_back(tmp);
            }
        }
        else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //    cin>>t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        Try(1);
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << endl;
    }
    return 0;
}