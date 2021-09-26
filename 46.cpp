#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> ans;
vector<int> a;
vector<int> Bool;

void backtracking(int start, vector<int> nums,int sum,vector<int> Bool){
    if(sum == nums.size())
    {
        ans.push_back(a);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(Bool[i]==1)
            continue;
        a.push_back(nums[i]);
        sum = sum + 1;
        Bool[i]=1;
        backtracking(i+1,nums,sum,Bool);
        a.pop_back();
        sum = sum - 1;
        Bool[i]=0;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    Bool.resize(nums.size(),0);
    backtracking(0,nums,0,Bool);
    return ans;

}

int main()
{
    vector<int> nums = {1,2,3};
    permute(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j <ans[i].size();j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}