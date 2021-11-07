#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                str[i] = '1';
                break;
            }
            str[i] = '0';
        }
        cout << str << endl;
    }
}