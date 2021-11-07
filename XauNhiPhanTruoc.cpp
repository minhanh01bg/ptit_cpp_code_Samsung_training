#include <bits/stdc++.h>
using namespace std;

string bin(string s)
{
    int i = s.size() - 1;
    while (s[i] == '0' && i >= 0)
        i--;
    //	cout<<i;
    if (i < 0)
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = '1';
    }
    else
    {
        s[i] = '0';
        for (int j = i + 1; j < s.size(); j++)
            s[j] = '1';
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        cout << bin(s) << endl;
    }
    return 0;
}