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

void backtracking(vector<int> &candidates, int target, int sum, vector<int> Bool, int start) //Bool��¼�����Ƿ��ù����ù�Ϊ1,startΪ��һ�ε���ʼλ��
{
    if (sum == target)
    { //��ֹ����
        ans.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size()+0; i++)
    {                     //�������е�ÿһ�����ּ�����һ��
        if (Bool[i] == 1) //�ж������Ƿ��ù���������һ������
            continue;
        sum = sum + candidates[i]; //�����ּ���
        if (sum > target)          //��Ϊ�ǵ������飬�����ʱ����target����ôֱ���˳�����Ĳ��ٿ�
            break;
        path.push_back(candidates[i]); //�����ּ���path����
        Bool[i] = 1;                   //���ֱ�ʹ�ù�
        backtracking(candidates,target,sum,Bool,i+1);
        //��������Ľڵ�
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
    sort(candidates.begin(), candidates.end()); //���������򣬴�С�����˳������

    vector<vector<int>> Ans = combinationSum2(candidates, target);
    for (int i = 0; i < Ans.size(); i++)
    {
        for (int j = 0; j < Ans[i].size(); j++)
            cout << Ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}