#include<iostream>

using namespace std;
int fun(int a[],int length,int N);
int main(){
    int n;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int N;
        cin>>N;
        cout<<fun(a,n,N)<<endl;
    }
    return 0;
}
int fun(int a[],int length,int N){
    int sum=0;
    int low=a[0],high=a[0];
    for(int i=1;i<length;i++){
        if(a[i]>=high+2)
            high=a[i];
        else if(high-low-N>0){
                sum+=(high-low-N);
                 high=a[i];
                low=a[i];
        }
    }
    if(high-low-N>0)
        sum+=(high-low-N);
    return sum;
}