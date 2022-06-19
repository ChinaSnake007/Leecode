#include<iostream>
using namespace std;

int M[510][510];
int N[510][510];
int jilu[510][510];
int m,n,a,b;
int Sum;
int jishu(int x,int y);
void dfs(int x,int y);

int main(){
    cin>>m>>n>>a>>b;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char ch;
            cin>>ch;
            M[i][j]=ch-48;
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(M[i][j]==1)
                N[i][j]=-1;
            else
                N[i][j]=jishu(i,j);
            // cout<<N[i][j]<<" ";
        }
        // cout<<endl;
    }

    dfs(a,b);
    if(Sum%2==1)
        cout<<"Superdog"<<endl;
    else
        cout<<"Spdddddddddd"<<endl;

    return 0;
}
int jishu(int x,int y){
    int Sum =0 ;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            // if(i<0||j<0)
            //     cout<<"越界"<<endl;
            Sum += M[i][j];
        }
    }
    return Sum;
}

void dfs(int x,int y){
    if(x<1||y<1||x>m||y>n)
    {
        jilu[x][y]=1;
        return;
    }

    if(N[x][y]==0){         //当这个点为0时，就要打开周围的所有点,并且周围所有的点访问完后，就结束
        jilu[x][y]=1;
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(jilu[i][j]==0)
                {
                    dfs(i,j);
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return;
    }
    else if(N[x][y]!=-1){                   //当这个点非0，直接打开，没有其他的操作
        if(jilu[x][y]==0){
            Sum += N[x][y];
            jilu[x][y]=1;      //这个非0的格子已经被加入到Sum中
        }
    }
}