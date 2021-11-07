#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
int b, k, m;

void Init()
{
    ll x = 1;
    a.push_back(1 % m);
    for (int i = 1; i < k; i++)
    {
        x *= b;
        x %= m;
        a.push_back(x);
    }
}

void Solve(string s)
{
    ll sum = 0;
    int l = k - 1;
    for (int i = 0; i < k; i++)
    {
        int tmp = (s[i] - '0');
        sum = (sum + (tmp % m * a[l]) % m) % m;
        l--;
    }

    int j = 0;
    ll res = sum;
    for (int i = k; i < s.length(); i++)
    {
        sum = (sum - (s[j] - '0') * a[k - 1] % m + m) * b % m;
        sum += (s[i] - '0') % m;
        sum %= m;
        res += sum;
        j++;
    }
    cout << res << endl;
}

int main()
{
    string s;
    cin >> s;
    cin >> k >> b >> m;
    Init();
    Solve(s);
    return 0;
}