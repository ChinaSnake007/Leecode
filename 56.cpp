//�ϲ�����
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
        //�Ƚ�intervals�����������������
        insertsort(intervals,intervals.size());
        //������󣬽�������ĺϲ�
        vector<int> a = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > a[1])
            { //��ǰ�����޷���a���кϲ���a���������
                // cout<<"["<<a[0]<<","<<a[1]<<"]"<<"�޷��ϲ���["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<endl;
                ans.push_back(a);
                a = intervals[i];
            }
            else
            { //����ǰ����ϲ���a��
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