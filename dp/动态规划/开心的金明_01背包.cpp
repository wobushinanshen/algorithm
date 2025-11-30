#include<iostream>
#include<algorithm>
using namespace std;
//01背包习题
int mon,n;
int cost[30],value[30];
int dp[30][30005];
int f(){
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=mon;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=mon;j++){
            dp[i][j]=dp[i-1][j];
            if(j-cost[i]>=0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i]]+value[i]);
            }
        }
    }
    return dp[n][mon];
}
int main(){
    cin>>mon>>n;
    int importance;
    for(int i=1;i<=n;i++){
        cin>>cost[i]>>importance;
        value[i]=cost[i]*importance;
    }
    cout<<f()<<endl;
}