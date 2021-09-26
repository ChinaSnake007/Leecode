#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<vector<int>> ans;
vector<int> path;

void backtracking(vector<int> &candidates, int target, int sum, vector<int> Bool, int start) //Bool记录数据是否被用过，用过为1,start为下一次的起始位置
{
    if (sum == target)
    { //终止条件
        ans.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size()+0; i++)
    {                     //将数组中的每一个数字加入试一下
        if (Bool[i] == 1) //判断数字是否被用过，遍历下一个数字
            continue;
        sum = sum + candidates[i]; //将数字加入
        if (sum > target)          //因为是递增数组，如果此时大于target，那么直接退出下面的不再看
            break;
        path.push_back(candidates[i]); //将数字加入path后面
        Bool[i] = 1;                   //数字被使用过
        backtracking(candidates,target,sum,Bool,i+1);
        //尝试另外的节点
        path.pop_back();
        Bool[i]=0;
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> Bool;
    Bool.resize(candidates.size(), 0);
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, Bool, 0);

    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    sort(candidates.begin(), candidates.end()); //将数组排序，从小到大的顺序排序

    vector<vector<int>> Ans = combinationSum2(candidates, target);
    for (int i = 0; i < Ans.size(); i++)
    {
        for (int j = 0; j < Ans[i].size(); j++)
            cout << Ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}