#include<iostream>
using namespace std;
int v,m,n;
int cost_v[55],cost_m[55],value[55];
int dp[55][405][405];//表示前i个物品在j体积k质量的背包中的最大value值
int f(){
    for(int i=1;i<=n;i++){
        dp[i][0][0]=0;
    }
    for(int i=1;i<=v;i++){
        dp[0][i][0]=0;
    }
    for(int i=1;i<=m;i++){
        dp[0][0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            for(int k=1;k<=m;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(k-cost_m[i]>=0&&j-cost_v[i]>=0){
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-cost_v[i]][k-cost_m[i]]+value[i]);

                }

            }
        }
    }
    return dp[n][v][m];
}
int main(){
    cin>>v>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>cost_v[i]>>cost_m[i]>>value[i];

    }
    cout<<f()<<endl;

}