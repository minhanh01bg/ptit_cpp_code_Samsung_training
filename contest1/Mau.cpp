#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define endl '\n'

#define ii pair<int, int>
#define iii map<int, int>

#define run()     \
    int tests;    \
    cin >> tests; \
    cin.ignore(); \
    while (tests--)
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cout.tie(0);                      \
    cin.tie(0);
using namespace std;
/*____________________________________MY CODE_______________________________________*/

#define int long long
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int min_pages(int arr[], int n, int m)
{
    long long sum = 0;
    if (n < m)
        return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int minimum = 0, maximum = sum;
    int result = INT_MAX;
    while (minimum <= maximum)
    {
        int mid = (minimum + maximum) / 2;
        if (isPossible(arr, n, m, mid))
        {
            result = min(result, mid);
            maximum = mid - 1;
        }
        else
            minimum = mid + 1;
    }
    return result;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int books[n];
        for (int i = 0; i < n; i++)
            cin >> books[i];
        cout << min_pages(books, n, m) << endl;
    }
    return 0;
}
