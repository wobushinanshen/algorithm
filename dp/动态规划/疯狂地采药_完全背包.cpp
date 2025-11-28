#include<iostream>
using namespace std;
//疯狂的采药：完全背包裸题(没有任何包装)
//每种草药可以无限摘
//01背包问题，我们知道，在(i,j)位置选择摘的话，也就是先把所有物品拿出来，先塞入当前物品，再加上剩余的空间能得到的最大价值
//而完全背包的不同就在这里，01背包是加上前i-1个物品，在j-cost[i]的答案(dp[i-1][j-coast[i]]+value[i])，也就是前i-1个物品在j-cost[i]空间内能得到的最大价值
//完全背包，因为一个物品有无数个，所以如果空间允许，还可以选择塞入当前物品，也就是比01背包多了一个物品可供选择,即dp[i][j-coast[i]]+value[i]

//因此唯一不同就在于一个地方
//
//二维版本
int t,m;
long long value[10005];
long long cost[10005];
long long dp[10005][10005];//含义是前i个株草药，在j时间内的最大价值
long long f1(int m,int t){
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=t;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            dp[i][j]=dp[i-1][j];
            if(j-cost[i]>=0){
                dp[i][j]=max(dp[i][j],dp[i][j-cost[i]]+value[i]);//与01背包不同在这里
            }
        }
    }
    return dp[m][t];
}

//空间压缩版本,要开long long!!!
long long dp1[10000010];
long long f2(int m,int t){
    //初始化
    for(int i=0;i<=t;i++){
        dp1[i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=cost[i];j<=t;j++){
//为啥这里又不是从右往左啦？因为与01背包不同，依赖关系变了
//当前位置依赖于其左边和正上方的答案，本质还是因为完全背包可以继续选择当前物品，因此
//从左往右，左边先得出答案，右边就刚好可以利用左边的答案了，而正上方的答案就是自己
            dp1[j]=max(dp1[j-cost[i]]+value[i],dp1[j]);
        }

    }
    return dp1[t];
}



int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>cost[i]>>value[i];

    }

    cout<<f1(m,t)<<endl;//二维空间
    cout<<f2(m,t)<<endl;//一维优化
}