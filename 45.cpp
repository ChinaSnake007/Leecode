/*跳跃游戏*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int jump(vector<int> &nums)
{
    if(nums.size()<=2)  return nums.size()-1;
    int begin = 0,Begin = 0;
    int end = 0, sum = 0;
    while(1){
        int buchang = 1;
        int farest = buchang + nums[begin + buchang];
        Begin = begin;
        for(buchang = 2;buchang < nums[begin]; buchang++){
            if(buchang + nums[begin + buchang] > farest){
                farest = buchang + nums[begin + buchang];
            }
        }

        end = begin + farest;
        begin = end;
        // if (end>=int(nums.size()-1))
        //     break;
        // else
        //     sum=sum+1;
    }
    
    
    return sum; 
}

int main()
{
    vector<int> nums={2,3,1,1,4};
    cout<<jump(nums)<<endl;

    return 0;
}