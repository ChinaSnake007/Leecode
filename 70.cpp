//��¥��
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>

using namespace std;
typedef long long ll;
class Solution {
public:
    int n;
    int sum = 0;
    //�ݹ��㷨����ʱ��ֻ�ܼ���43���ڵ�¥��
    void pa(int N){
        if(N == n){
            sum++;
            return;
        }
        else if(N >n)
            return;
        pa(N+1);
        pa(N+2);
    }
    //��̬�滮�㷨
    int climbStairs(int n) {
        // this->n = n;
        // pa(0);
        // return sum;
        
    }
};


int main(){
    Solution s;
    cout<<s.climbStairs(44)<<endl;
    return 0;
}