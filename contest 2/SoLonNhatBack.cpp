#include <bits/stdc++.h>
using namespace std;
string s, s1;
int k;
bool stop = false;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> s;
        for (int i = 0; i < s.size(); i++)
        {
            char Max = s[s.size() - 1];
            int vt = s.size() - 1;
            for (int j = s.size() - 1; j > i && k > 0; j--)
            {
                if (Max < s[j])
                {
                    Max = s[j];
                    vt = j;
                }
            }
            if (Max > s[i] && k > 0)
            {
                swap(s[i], s[vt]);
                k--;
            }
        }
        cout << s << endl;
    }
}