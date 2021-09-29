//爬楼梯
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
    //递归算法，超时，只能计算43以内的楼梯
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
    //动态规划算法
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