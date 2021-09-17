/*下一个排列*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void nextPermutation(vector<int> &nums);
int duan(vector<int> nums);
bool comp(int x,int y){
    return x<y;
}



int main()
{
    vector<int> nums={3,1,2};
    nextPermutation(nums);
    for(auto it:nums){
        cout<<it;
    }
    return 0;
}
void nextPermutation(vector<int> &nums)
{
    if(nums.size()==1)
        return; 
    if(duan(nums)==1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i=nums.size()-1; i>=0; i--){
        if(nums[i]>nums[i-1]){
            int a = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = a;
            sort(nums.begin(), nums.end(),comp);
            return;
        }
    }
    
}
// 判断序列是否是一个递减序列
int duan(vector<int> nums){
    for(int i = 1; i < nums.size();i++){
        if(nums[i]>nums[i-1])
            return 0;
    }
    return 1;   
}
