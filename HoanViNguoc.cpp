#include <iostream>
using namespace std;

int t, n, a[100];

bool chuaxet[100];

void xuat()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << " ";
}

void back(int i)
{
    for (int j = n; j >= 1; j--)
    {
        if (chuaxet[j])
        {
            a[i] = j;
            chuaxet[j] = false;
            if (i == n)
                xuat();
            else
                back(i + 1);
            chuaxet[j] = true;
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            chuaxet[i] = true;
        }
        back(1);
        cout << endl;
    }
    return 0;
}