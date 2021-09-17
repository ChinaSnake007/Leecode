//Z字形转换
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string convert(string s,int numRows);
string solution(string s,int numRows);


int main(){
    string s="PAYPALISHIRING";
    int numRows = 2;
    while(cin>>s>>numRows){
        cout<<solution(s,numRows)<<endl;
    }
 /*   cin>>s;
    cin>>numRows;
    cout<<convert(s,numRows)<<endl;*/
    return 0;
}
string convert(string s,int numRows){
    if(numRows==1)
        return s;
    else
    {
        int NumRoms=numRows;
    NumRoms>1?NumRoms:2;
    int n=numRows+1,m=s.length()/(NumRoms-1)+1;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            a[i][j]='\0';
    }

    int k=1;
    a[0][0]=s[0];
    int lie=0;          //记录当前所在列
    while(k<s.length()){
        for(int i=1;i<numRows;i++){
            if(k<s.length())
                a[i][lie]=s[k++];
            else
                break;
        }
        lie++;
        for(int i=numRows-2;i>=0;i--){
            if(k<s.length())
                a[i][lie]=s[k++];
            else
                break;
        }
        lie++;
    }
    string str;

    for(int i=0;i<numRows;i++){
        for(int j=0;j<m;j++)
            if(a[i][j]!='\0')
            {
                str=str+a[i][j];
            }
    }
        return str;
    }
}

string solution(string s,int numRows){
    if(numRows==1)
        return s;
    
    string Row[numRows];
    int goingdown=1;
    int row = 0;
    for(char c:s){
        Row[row]+=c;

        if(row==0)
            goingdown=1;
        else if(row==numRows-1)
            goingdown=-1;
        row+=goingdown;
    }
    string str;
    for(int i=0;i<numRows;i++){
        str+=Row[i];
    }
    return str;

}