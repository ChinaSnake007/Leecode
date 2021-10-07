//排列序列
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>

using namespace std;
class Solution {
public:
    vector<int> jie = {1,1,2,6,24,120,720,5040,40320,362880};
    int k,n;
    string ans;
    // void backtracking(int ceng,int sum){
    //     //ceng:记录当前层数，方便计算数字。sum:记录当前是第几个数字。
        
    //     if(sum == k){

    //         return;
    //     }
    // }

    void backtracking(int sum,vector<int> Bool,int ceng){
        for(int i=1;i <= n;i++){
            if(Bool[i] == 0){
                if(sum + jie[ceng-1] < k)
                {
                    sum = sum + jie[ceng-1];
                    continue;
                }
                else{//从此节点进入
                    Bool[i] = 1;
                    ans = ans + char(i+48);
                    backtracking(sum,Bool,ceng-1);
                    break;
                }
            }
        }

    }
    string getPermutation(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> Bool;
        Bool.resize(n+1);
        backtracking(0,Bool,n);
        return ans;
    }
};

using namespace std;
typedef long long ll;

int main(){
    Solution s;
    
    cout<<s.getPermutation(4,24)<<endl;
    return 0;
}