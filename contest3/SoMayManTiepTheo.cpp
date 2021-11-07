// #include <bits/stdc++.h>
// using namespace std;
// int Stoi(string s)
// {
//     int d = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         d = (s[i] - '0') + d * 10;
//     }
//     return d;
// }
// vector<string> vec;
// int k = 500;
// void generatePrintBinary()
// {
//     queue<string> q;

//     q.push("4");
//     q.push("7");
//     while (k--)
//     {
//         string s1 = q.front();
//         q.pop();
//         string sk = q.front();
//         q.pop();
//         vec.push_back(s1);
//         vec.push_back(sk);
//         string s2 = s1;
//         string sk1 = sk;
//         q.push(s1.append("4"));
//         q.push(s2.append("7"));
//         q.push(sk.append("4"));
//         q.push(sk1.append("7"));
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     generatePrintBinary();
//     while (t--)
//     {
//         int a, b;
//         cin >> a >> b;
//         for (int i = 0; i < vec.size(); i++)
//         {
//             cout << vec[i] << " ";
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ib ios_base::sync_with_stdio(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define test() \
    ib;        \
    int t;     \
    cin >> t;  \
    while (t--)
#define l() length()
#define sz() size()
#define el endl
#define pb(a) push_back(a)
#define reset(a) memset(a, 0, sizeof(0))
#define ci cin
#define co cout

#define INF 0x3f3f3f3f

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> num;
    num.pb(4);
    num.pb(7);
    for (int i = 1; i <= 1022; i++)
    {
        if (i % 2 != 0 && num[i / 2] * 10 + 4 <= 777777777)
            num.pb(num[i / 2] * 10 + 4);
        else if (i % 2 != 1 && num[(i / 2) - 1] * 10 + 7 <= 777777777)
            num.pb(num[(i / 2) - 1] * 10 + 7);
        else if (num[i / 2] * 10 + 4 > b || num[(i / 2) - 1] * 10 + 7 > b)
            break;
    }
    ll sum = 0;
    int j = 0;
    for (int i = a; i <= b; i++)
    {
        if (num[j] >= i)
        {
            sum += num[j];
        }
        else
        {
            j++;
            i--;
        }
    }
    cout << sum;
    return 0;
}