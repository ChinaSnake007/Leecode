#include<iostream>
using namespace std;

int jie(int n){
    int sum = 1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}

int main(){
    int T;
    cin>>T;
    while( T--){
        int k;
        cin>>k;
        if(k==1){
            cout<<"1"<<endl;
            continue;
        }
        int i;
        for(i=2;;i++){
            if(k%i!=0)
                break;
        }
        //此i为缺失的一个i
    }


    return 0;
}