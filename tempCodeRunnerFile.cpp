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
        //一旦出现中断，就立即清空栈
        else{
            S = stack<char>();
            S.push(s[i]);
            if(num>nummax){
                nummax = num;
            }
            num=0;
        }
    }
    return num*2;