#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

// int rongji(vector<int> &nums, int start, int end)
// { //��������i������j֮�����ˮ���ݻ�
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
//     cout << "���Ϊ" << start << "�յ�Ϊ" << end << "���ݻ�Ϊ��"<< sum << endl;
//     return sum;
// }

// int trap(vector<int> &height)
// {
//     int sum = 0, Sum = 0;
//     int start = 0;
//     for (int j = start + 1; j < height.size(); j++)
//     {   
//         if(height[start] == 0){ //�߶�Ϊ0�ģ�������Ϊ��һ������
//             start++; 
//             continue;        
//         }
//         //Ѱ���յ�����                           
//         if (height[j] >= height[start]) //�ҵ������յ�����
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

int trap(vector<int> &nums){


}

int main()
{
    vector<int> height = {9,6,8,8,5,6,3};
    cout<<trap(height)<<endl;
    return 0;
}