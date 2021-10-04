//螺旋矩阵Ⅱ
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int sum = 1;
    void dfs(int a, int b)
    {
        // ans[a][b] = sum++;
        if(b+1 < n&&ans[a][b+1]==0)
        {
            if(a!=0 && ans[a-1][b] == 0)
                int ss;
            else{
                ans[a][b+1] = sum++;
                dfs(a,b+1);
            }
        }
        if(a+1 < n&&ans[a+1][b]==0)              //没有到边界，而且没有被访问过
        {
            ans[a+1][b] = sum++;
            dfs(a+1,b);
        }
        
        if(b-1 >= 0&&ans[a][b-1]==0)
        {
            ans[a][b-1] = sum++;
            dfs(a,b-1);
        }
        if(a-1 >= 0&&ans[a-1][b]==0)
        {
            ans[a-1][b] = sum++;
            dfs(a-1,b);
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        for(int i=0; i<n; i++)
        {
            vector<int> a;
            a.resize(n,0);
            ans.push_back(a);
        }
        this->n = n;
        ans[0][0] = sum++;
        dfs(0,0);
        

        return ans;
    }
};

int main(){
    Solution solution;
    int n = 3;
    vector<vector<int>> ans = solution.generateMatrix(n);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 


    return 0;
}