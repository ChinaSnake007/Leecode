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
    int sum = 0;
    int m,n;
    void dfs(int M, int N)
    {
        if(M == m && N == n){
            sum = sum + 1;
            return;
        }
        if(M < m)
            dfs(M + 1,N);
        if(N < n)
            dfs(M,N + 1);
    }
    int uniquePaths(int m, int n)
    {
        this->m = m;
        this->n = n;
        // dfs(1,1);
        // return sum;
        int dp[m][n];
        for(int i=0; i<m; i++)
            dp[i][0]=1;
        for(int j=0; j<n; j++)
            dp[0][j]=1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    } 
};

int main()
{
    Solution solution;
    cout << solution.uniquePaths(3, 7) << endl;
    return 0;
}