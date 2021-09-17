#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int longestValidParentheses(string s)
{
    if (s.length() == 0)
        return 0;
    stack<char> S;
    int num=0;
    int nummax=0;
    S.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(S.empty()){
            S.push(s[i]);
            continue;
        }
        if(S.top()=='('&&s[i]==')'){
            num++;
            S.pop();
        }
        //һ�������ж�,���s[i]�Ƿ�Ϊ')',�����,ֱ�����¿�ʼ�������ջ
        else if(s[i]==')'){
            S = stack<char>();
            S.push(s[i]);
            if(num>nummax){
                nummax = num;
            }
            num=0;
        }
    }
    return num*2;
}
int main()
{
    string s;
    while(cin>>s){
        cout<<longestValidParentheses(s)<<endl;
    }
    return 0;
}