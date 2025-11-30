#include<iostream>
#include<algorithm>
using namespace std;
//跟01背包的不同：每种物品是有限个的，题目会给定每个物品的个数
//那就是每个物品多了一个属性而已嘛
//那就多开一个数组，记录每个物品个数(也可能是无限个)
int n,time_;
int cost[10005],value[10005],num[10005];
int dp[10005][1005];
int f1(){
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=time_;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=time_;j++){
            dp[i][j]=dp[i-1][j];
            //num[i]等于0的时候，当作完全背包(始终记得这个表是一行一行填的喔，这样就很清楚过程)
            if(num[i]==0&&j-cost[i]>=0){
                dp[i][j]=max(dp[i][j-cost[i]]+value[i],dp[i][j]);

            }

            else{
                for(int k=1;k<=num[i]&&j-cost[i]*k>=0;k++){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k*cost[i]]+k*value[i]);
                    //先把所有物品拿出，分别试试放入1到num[i]个物品，再加上剩余的空间在i-1行所能得到的最大值，
                    //其实就跟01背包一样的

                }
            }

        }
    }
    return dp[n][time_];
}

int main(){
    //遇到时间输入hh:mm形式，可以这样写：
    int hour1,minute1,hour2,minute2;
    char ch;
    cin>>hour1>>ch>>minute1>>hour2>>ch>>minute2>>n;
    time_=60*(hour2-hour1)+minute2-minute1;
    for(int i=1;i<=n;i++){
        cin>>cost[i]>>value[i]>>num[i];
    }
    cout<<f1()<<endl;



}