#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

// class Solution
// {
// public:
//     vector<vector<int>> nums;
//     int sum = 0;
//     int M, N;
//     void dfs(int m, int n)
//     {
//         if (m == M && n == N && nums[M-1][N-1]==0)
//         {
//             sum = sum + 1;
//             return;
//         }
//         if (m < M && nums[m][n-1] == 0)
//             dfs(m + 1, n);
//         if (n < N && nums[m-1][n] == 0)
//             dfs(m, n + 1);
//         return;
//     }

//     int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//     {
//         this->nums = obstacleGrid;
//         M = obstacleGrid.size();
//         N = obstacleGrid[0].size();
//         if(obstacleGrid[0][0] == 1)
//             return 0;
//         dfs(1, 1);
//         return sum;
//     }
// };

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    if (obstacleGrid[0][0] == 1)
        return 0;
    int M = obstacleGrid.size();
    int N = obstacleGrid[0].size();
    int dp[M][N];
    int i;
    for (i = 0; i < M; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            dp[i][0] = 0;
            break;
        }
        else
            dp[i][0] = 1;
    }
    for (int j = i; j < M; j++)
        dp[j][0] = 0;
    for (i = 0; i < N; i++)
    {
        if (obstacleGrid[0][i] == 1)
        {
            dp[0][i] = 0;
            break;
        }
        else
            dp[0][i] = 1;
    }
    for (int j = i; j < N; j++)
        dp[0][j] = 0;
    for (int i = 1; i < M; i++)
        for (int j = 1; j < N; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[M - 1][N - 1];
}
int main()
{
    vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}