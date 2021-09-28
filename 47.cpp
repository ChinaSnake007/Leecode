#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<vector<int>> ans;
vector<int> path;
int sum = 0;

void backtracking(vector<int> nums,int sum,vector<int> Bool){
    if(sum == nums.size()){
        ans.push_back(path);
        return;
    }
    vector<int> cun;
    cun.push_back(-11);
    for(int i = 0; i < nums.size();i++){
        if(nums[i]!=cun.back()&&Bool[i]==0){
            cun.push_back(nums[i]);
            path.push_back(nums[i]);
            Bool[i] = 1;
            sum = sum + 1;
            backtracking(nums,sum,Bool);
            sum =sum - 1;
            Bool[i] = 0;
            path.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> Bool;
    Bool.resize(nums.size());

    backtracking(nums,0,Bool);
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2};
    permuteUnique(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j <ans[i].size();j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}