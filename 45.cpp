/*跳跃游戏*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

int jump(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size() - 1;
    int begin = 0, Begin = 0;
    int end = 0, sum = 1;               //end记录当前节点移动后所能到达的最远位置
    while (1)
    {
        int farest = -1;
        for (int buchang = 1; buchang <= nums[begin]; buchang++)
        { //遍历从此节点的所有可能到达的位置，选取最远距离
            if (nums[begin + buchang] != 0 || (nums[begin + buchang] == 0 && begin + buchang == nums.size() - 1))
            { //括号内的条件是为了确保，0不会出现在跳跃的过程中，只会出现在终点的位置
                if(buchang + nums[begin + buchang] > farest)
                {
                    end = begin + buchang;                  //更新起始位置
                    farest = buchang + nums[begin + buchang]; //更新最大距离
                }
            }

            if (begin + buchang >= nums.size() - 1) //如果到达的位置超过了数组的最大长度，表示已经可以到达终点，不需要继续
            {
                end = begin + buchang;
                break;
            }
        }
        begin = end;            //更新起始位置
        if (end >= nums.size()-1)
            break;
        else
            sum = sum + 1;
    }
    return sum;
}

int gaijinjump(vector<int> &nums){
    if (nums.size() <= 2)
        return nums.size() - 1;
    vector<int> dp;
    dp.resize(nums.size(),10002);
    dp[0] = 0;
    for(int i=0; i<nums.size();i++){
        for(int j=1;j<=nums[i];j++){
            if(i+j>=nums.size() - 1)
                return dp[i]+1;
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    return dp[nums.size()-1];
}

int main()
{
    vector<int> nums = {3,2,1};
    cout << jump(nums) << endl;
    cout << gaijinjump(nums) << endl;
    return 0;
}