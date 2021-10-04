//区间插入
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i;
        //为新增区间的左区间找到合适位置
        for (i = 0; i < intervals.size();i++){
            //判断新增区间的左区间是否落在，当前区间内及左边。
            if(newInterval[0] >= intervals[i][0]&&newInterval[0] <= intervals[i][1]){
                newInterval[0] = intervals[i][0];
                break;
            }else if(newInterval[0]<= intervals[i][0]){
                break;
            }
            ans.push_back(intervals[i]);
        }
        //为新增区间的右区间找到合适位置
        for(int j = i;j < intervals.size();j++){
            if(intervals[j][0] > newInterval[1])
            {
                ans.push_back(newInterval);
                for(int i = j;i < intervals.size();i++)
                    ans.push_back(intervals[i]);
                newInterval.resize(0);
                break;
            }else if(intervals[j][0] <= newInterval[1] && intervals[j][1] >= newInterval[1]){   
                newInterval[1] = intervals[j][1];
            }
        }
        if(!newInterval.empty())
            ans.push_back(newInterval);
        return ans;
    }
};
int main()
{
    vector<vector<int>> intervals ={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> ans;
    vector<int> inter = {4, 8};
    Solution solution;
    ans = solution.insert(intervals, inter);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << " " << endl;
    }
    // for (int i = 0; i < intervals.size(); i++)
    // {
    //     cout << intervals[i][0] << " " << intervals[i][1] << " " << endl;
    // }
    return 0;
}