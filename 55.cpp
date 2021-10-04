#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;

class Solution
{
public:
    //ֱ�ӽ������
    bool canJump1(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();)
        {
            if (nums[i] != 0)
                i = i + nums[i];
            else
            {
                //�ж�0֮ǰ����û�п��������Ĳ���
                int j;
                for (j = i - 1; j >= 0; j--)
                {
                    if (j + nums[j] > i)
                        break;
                }
                if (j < 0)
                    return 0;
            }
        }

        return 1;
    }
    //��̬�滮�������
    bool canJump(vector<int> &nums)
    {
        int a = nums[0], b;
        for (int i = 1; i < nums.size(); i++)
        {
            a--;
            if (a < 0)
                return 0;
            b = nums[i];
            a = max(a, b);
            if (a == 0 && i != nums.size() - 1)
                return 0;
        }
        return 1;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {5,2,0,0};
    cout << solution.canJump(nums) << endl;

    return 0;
}