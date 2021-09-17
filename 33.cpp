/*ËŃË÷Đý×ŞĹĹĐňĘý×é*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int search(vector<int> &nums, int target);

int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    int target = 0;
    cout<<search(nums, target)<<endl;
    return 0;
}

int search(vector<int> &nums, int target)
{
    for(int i=0; i<nums.size();i++)
        if(nums[i] == target)
            return i;
    
    return -1;
}