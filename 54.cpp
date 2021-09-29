//螺旋矩阵
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
class Solution
{
public:
    vector<vector<int>> dp;
    vector<int> path;
    int m, n;
    vector<vector<int>> matrix;
    void dfs(int a, int b)
    {
        path.push_back(matrix[a][b]);
        if(b+1 < n&&dp[a][b+1]==0)
        {
            if(a!=0 && dp[a-1][b] == 0)
                int ss;
            else{
                dp[a][b+1] = 1;
                dfs(a,b+1);
            }
        }
        if(a+1 < m&&dp[a+1][b]==0)              //没有到边界，而且没有被访问过
        {
            dp[a+1][b] = 1;
            dfs(a+1,b);
        }
        
        if(b-1 >= 0&&dp[a][b-1]==0)
        {
            dp[a][b-1] = 1;
            dfs(a,b-1);
        }
        if(a-1 >= 0&&dp[a-1][b]==0)
        {
            dp[a-1][b] = 1;
            dfs(a-1,b);
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if(matrix.size() == 1&&matrix[0].size() == 1) 
            return matrix[0];
        m = matrix.size();
        n = matrix[0].size();
        this->matrix = matrix;
        for (int i = 0; i < m; i++)
        {
            vector<int> a;
            a.resize(n, 0);
            dp.push_back(a);
        }
        dp[0][0] = 1;
        dfs(0, 0);
        return path;
    }
};
int main()
{
    vector<vector<int>> matrix = {{1},{2},{3}};
    Solution solution;
    vector<int> A = solution.spiralOrder(matrix);
    for (auto a : A)
        cout << a << " ";

    return 0;
}