/*最长公共前缀*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string longestCommonPrefix(vector<string> &strs);

int main()
{
    vector<string> strs= {"ab","a"};
    
    cout<<longestCommonPrefix(strs)<<endl;

    return 0;
}

string longestCommonPrefix(vector<string> &strs)
{
    if(strs.size()==1) return strs[0];
    int flag=0;
    int min=strs[0].length();
    for(auto &SS:strs){
        if(min>SS.length()){
            min=SS.length();
        }
    }

    while(min--){
        for(int i=1;i<strs.size();i++){
            if(strs[i].substr(flag,1)!=strs[0].substr(flag,1))
                return strs[0].substr(0,flag);
        };
        flag++;
    }
    return strs[0].substr(0,flag);

}