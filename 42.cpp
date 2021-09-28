#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
void bianli(vector<int> a){
    for(auto ans:a)
        cout<<ans<<" ";
    cout<<endl;
}
// int rongji(vector<int> &nums, int start, int end)
// { //计算柱子i和柱子j之间的雨水的容积
//     int sum = 0;
//     for (int i = start + 1; i < end; i++)
//     {
//         if (nums[end] <= nums[start])
//         {
//             int add = (nums[end] - nums[i]) > 0 ? 1 : 0;
//             sum = sum + add * (nums[end] - nums[i]);
//         }
//         else
//         {
//             int add = (nums[start] - nums[i]) > 0 ? 1 : 0;
//             sum = sum + add * (nums[start] - nums[i]);
//         }
//     }
//     cout << "起点为" << start << "终点为" << end << "的容积为："<< sum << endl;
//     return sum;
// }

// int trap(vector<int> &height)
// {
//     int sum = 0, Sum = 0;
//     int start = 0;
//     for (int j = start + 1; j < height.size(); j++)
//     {   
//         if(height[start] == 0){ //高度为0的，不可作为第一个柱子
//             start++; 
//             continue;        
//         }
//         //寻找终点柱子                           
//         if (height[j] >= height[start]) //找到理想终点柱子
//         {
//             sum = sum + rongji(height, start, j);
//             start = j;
//             Sum = 0;                    
//         }
//         else
//         {
//             if(rongji(height, start, j) > Sum) //
//                 Sum = rongji(height, start, j);
//         }
//     }
//     sum = sum + Sum;
//     return sum;
// }

int trap1(vector<int> &nums){
    //动态规划解法
    if(nums.size() <= 2)
        return 0;
    int size = nums.size();
    vector<int> leftMax;
    leftMax.reserve(nums.size());
    leftMax[0] = 0;
    for(int i = 1; i < size;i++)
        leftMax[i] = max(leftMax[i-1],nums[i-1]);
    vector<int> rightMax;
    rightMax.resize(nums.size());
    leftMax[nums.size()-1] = 0;
    for(int i = nums.size() - 2;i >= 0;i--){
        rightMax[i] = max(rightMax[i+1],nums[i+1]);
    }
    int sum = 0;
    for(int i = 0; i < nums.size();i++)
       sum += (min(leftMax[i],rightMax[i]) - nums[i])<0?0:(min(leftMax[i],rightMax[i]) - nums[i]);
    return sum;
}
//单调栈
int trap2(vector<int> &nums){
    int ans = 0;
    int i = 0;
    stack<int> S;
    while(i < nums.size()){
        while(!S.empty()&&nums[i] > nums[S.top()]){
            int top = S.top();
            S.pop();
            if(S.empty())
                break;
            ans += (i - S.top() - 1)*(min(nums[i],nums[S.top()]) - nums[top]);
        }
        S.push(i++);
    }
    return ans;
}

//双指针
int trap3(vector<int> &height){
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}


int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // bianli(height);
    cout<<trap3(height)<<endl;
    return 0;
}