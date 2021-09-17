/*外观数列*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string fun(string s){
    string S="";
    char a = s[0];
    int sum = 1;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == a)
            sum++;
        else{
            S = S + char(sum+48) + a;
            a = s[i];
            sum = 1;
        }
    }
    S = S + char(sum+48) + a;
    return S;
}

string countAndSay(int n)
{
    if(n==1)    return "1";
    string S="1";
    for(int i=2;i<=n;i++){
        S=fun(S);
    }
    return S;
}

int main()
{
    cout<<countAndSay(5);

    return 0;
}