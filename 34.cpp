#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    ans.resize(2,0);
    if(nums.size()==0){
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int start = 0,end = nums.size()-1;
    int mid;
    while(start<=end){
        mid = (start + end)/2;
        if(nums[mid]>target)
            end = mid - 1;
        else if(nums[mid]<target)
            start = mid + 1;
        else
            break;
    }

    if(start<=end){
        int i;
        for(i = mid;i<=nums.size()-1;i++)
            if(nums[i]>target)
                break;
        ans[1] = i -1;
        for(i = mid;i>=0;i--)
            if(nums[i]<target)
                break;
        ans[0] = i + 1;  
    }
    else{
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,8,8,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums,target);
    for(auto a:ans){
        cout<<a<<endl;
    }
    return 0;
}