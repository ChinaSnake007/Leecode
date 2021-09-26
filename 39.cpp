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
        if (sum == target) {                    //终止条件
            result.push_back(path);
            return;
        }

        // 如果 sum + candidates[i] > target 就终止遍历
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
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/combination-sum/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-7tum/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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