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
    int end = 0, sum = 1;
    int sum = 1;
    while (1)
    {
        int farest = -1;
        for (int buchang = 1; buchang <= nums[begin + buchang]; buchang++)
        { //遍历此节点的所有可能到达的位置，选取最远距离
            if (buchang + nums[begin + buchang] > farest && (nums[begin + buchang] != 0 || begin + buchang == nums.size() - 1))
            { //括号内的条件是为了确保，0不会出现在跳跃的过程中，只会出现在终点的位置
                {
                    if (begin + buchang >= nums.size()) //如果到达的位置超过了数组的最大长度，表示已经可以到达终点，不需要继续
                    {
                        begin = begin + buchang;
                        break;
                    }
                    begin = begin + buchang;                  //更新起始位置
                    farest = buchang + nums[begin + buchang]; //更新最大距离
                }
            }
        }
        if (begin >= nums.size())
            break;
        else
            sum = sum + 1;
    }
    //     int buchang = 1;
    //     int farest = buchang + nums[begin + buchang];
    //     Begin = begin;
    //     for (buchang = 2; buchang <= nums[begin]&&begin + buchang <= nums.size()-1; buchang++)     //保证不会超出数组的长
    //     {
    //         if (buchang + nums[begin + buchang] > farest && nums[begin + buchang] != 0)
    //         {
    //             if(begin + buchang >= nums.size()-1)
    //                 break;
    //             farest = buchang + nums[begin + buchang];
    //         }
    //     }
    //     if(buchang == 2)
    //         buchang = 1;
    //     end = begin + buchang;
    //     begin = end;
    //     if (end >= int(nums.size() - 1))
    //         break;
    //     else
    //         sum = sum + 1;
    // }

    return sum;
}

int main()
{
    vector<int> nums = {1, 2, 0, 1};
    cout << jump(nums) << endl;

    return 0;
}