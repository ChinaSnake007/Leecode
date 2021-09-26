#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include<algorithm>
using namespace std;
typedef long long ll;

void bianli(vector<int> a){
    for(auto ans:a)
        cout<<ans<<" ";
    cout<<endl;
}

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {                    //��ֹ����
            result.push_back(path);
            return;
        }

        // ��� sum + candidates[i] > target ����ֹ����
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // ��Ҫ����
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// ���ߣ�carlsun-2
// ���ӣ�https://leetcode-cn.com/problems/combination-sum/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-7tum/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    for(int i=0;i<3;i++){
        vector<int> a;
        a.resize(i+1,i);
        ans.push_back(a);
    }
    return ans;
}

int main()
{
    vector<int> candidates = {2,3,6,7};
    sort(candidates.begin(),candidates.end());
    int target = 7;
    Solution solution;
    vector<vector<int>> ans = solution.combinationSum(candidates, target);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j <ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }



    return 0;
}