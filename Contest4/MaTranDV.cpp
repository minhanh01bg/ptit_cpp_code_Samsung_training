#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 4

int getSum(int r1, int r2, int c1, int c2,
           int dp[N + 1][N + 1])
{
    return dp[r2][c2] - dp[r2][c1] - dp[r1][c2] + dp[r1][c1];
}

bool sumFound(int K, int S, int grid[N][N])
{
    int dp[N + 1][N + 1];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + grid[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int sum = getSum(i, i + K, j, j + K, dp);

            if (sum == S)
                return true;
        }
    return false;
}

int main()
{
    int grid[N][N] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};
    int K = 2;
    int S = 14;

    if (sumFound(K, S, grid))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}