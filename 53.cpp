#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = max;
        for(int i = 1;i < nums.size();i++){
            if(sum < 0)
                sum = nums[i];
            else
                sum = sum + nums[i];
            if(sum > max)
                max = sum;
            cout << "sum = " << sum << "\tmax = " << max << endl;
        }
        return max;
    }

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;


    return 0;
}