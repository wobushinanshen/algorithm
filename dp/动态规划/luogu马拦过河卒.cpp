#include<iostream>
using namespace std;
//A：原来递推就是dp吗。
//B：是的，更准确地说，递推是dp的一种实现方式，是一种自底向顶的过程，这是dp的特点

//A：有时候确实直接从递推入手就可以做出自底向顶的dp，没有从递归入手这么麻烦
//B：的确如此，但是递归的思维也不可少啊，你想想你的状态转移方程是怎么想出来的。
//A：噢，确实用到递推分解问题的思想。

long long dp[30][30];
long long ma[30][30];
//确定马的位置，
void k(long long x,long long y){
    ma[x][y]=1;
    ma[x-2][y-1]=1;
    ma[x-1][y-2]=1;
    ma[x+1][y-2]=1;
    ma[x+2][y-1]=1;
    ma[x+2][y+1]=1;
    ma[x+1][y+2]=1;
    ma[x-1][y+2]=1;
    ma[x-2][y+1]=1;
}
int main(){
    long long n,m,x,y;
    cin>>n>>m>>x>>y;
    n+=2;//所有坐标加2，相当于把整体往数组右下角平移（棋盘没动，卒和马动）
    //这样就算马在边缘位置，也不可能越界
    m+=2;
    x+=2;
    y+=2;
    k(x,y);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i==2&&j==2)dp[i][j]=1;
            else if(ma[i][j]==1){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            

        }
    }
    cout<<dp[n][m];
}
