/*串联所有单词的子串*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> findSubstring(string s, vector<string> &words);

int main()
{
    string s= "barfoothefoobarman";
    vector<string> words={"foo","bar"};

    vector<int> a = findSubstring(s, words);
    for(auto i:a)
        cout<<i<<endl;
    return 0;
}
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> a;
    a.resize(words.size());
    

    return a;
}