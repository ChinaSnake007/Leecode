//合并区间
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
    void insertsort(vector<vector<int>> &intervals, int intervalsSize)
    {
        for (int i = 1; i < intervalsSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][0] > intervals[i][0])
                {
                    vector<int> tmp = intervals[j];
                    intervals[j] = intervals[i];
                    intervals[i] = tmp;
                }
            }
        }
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        //先将intervals根据左区间进行排序
        insertsort(intervals,intervals.size());
        //排序完后，进行区间的合并
        vector<int> a = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > a[1])
            { //当前区间无法和a进行合并，a便独立出来
                // cout<<"["<<a[0]<<","<<a[1]<<"]"<<"无法合并到["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<endl;
                ans.push_back(a);
                a = intervals[i];
            }
            else
            { //将当前区间合并到a中
                a[1] = max(intervals[i][1],a[1]);
            }
        }
        ans.push_back(a);
        return ans;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
    Solution solution;
    vector<vector<int>> ans = solution.merge(intervals);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i][0] << " " << ans[i][1] << " " << endl;
    // }
    // for (int i = 0; i < intervals.size(); i++)
    // {
    //     cout << intervals[i][0] << " " << intervals[i][1] << " " << endl;
    // }
    return 0;
}