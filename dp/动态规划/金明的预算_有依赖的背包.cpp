#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//有依赖的背包和01背包区别？
//看完题目后，可以知道，所有物品可以分为主件和附件，而且附件必须要在主件购买的情况下才能购买
//这就是依赖关系，如果只考虑主件，而把附件的买或者不买当作主件的一个选择，那么就跟01背包很像了
//01背包对每个物品只有选或者不选两种，而依赖背包对每个物品是不选或者怎么选
//什么意思呢，比如有1 2 3号主件，其中1号主件附带着2个附件，2号主件附带着1个附件，3号主件没有附件
//那么对1号主件，要么不选，要是选的话，还要分怎么选(多种选择)--只买主件，只买主件和第一个附件，只买主件和第二个附件，主件和两个附件全都买
//对2号主件，要么不选，选的话，还要分--只买主件，主件和附件都买
//对3号主件，就是只有买和不买两种选择
//相比于01背包，每个物品有可能会多几个选择而已
//然后就是一样的啦，

//dp[i][j]数组的含义依然是前i个物品，在j钱的情况下能得到的最大满足度
//至于依赖关系怎么处理呢？可以再定义三个数组king(bool) fans(int) follows(int)，分别表示
//i位置上的物品是否为主件，如果是，fans则表示有几个附件，follows表示附件的下标

int money,m;
int value[65];//这里表示重要度*价格
int cost[65];
bool king[65];
int fans[65];
int follows[65][2];//每个主件最多有2个附件
int dp[65][32005];

int f(){
    //初始化
    for(int i=1;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=money;i++){
        dp[0][i]=0;
    }
    int p=0;//p用来记录上一个主件所在的行数(脑海里要有一张dp二维表)
    for(int i=1;i<=m;i++){
        //是主件的话，才进行展开
        if(king[i]){
        for(int j=1;j<=money;j++){
            //不选的情况
            dp[i][j]=dp[p][j];
            //只买主件的情况
            if(j-cost[i]>=0){
                dp[i][j]=max(dp[i][j],dp[p][j-cost[i]]+value[i]);//这里注意dp[i][j]其实是指dp[p][j]，
                //                                                   这里按一个流程去捋下来，每个选择中的dp[i][j]都是上一个选择中决斗出来的最大值
                //                                                   (好处是不用记录每个选择对应的值，最后再取最大)
            }
            //用fan1,fan2判断主件是否有附件1，附件2
            int fan1=-1,fan2=-1;
            if(fans[i]>=1)fan1=1;
            if(fans[i]>=2)fan2=1;
            //买主件和附件1
            if(fan1!=-1&&j-cost[i]-cost[follows[i][0]]>=0){
                dp[i][j]=max(dp[i][j],dp[p][j-cost[i]-cost[follows[i][0]]]+value[i]+value[follows[i][0]]);
            }
            //买主件和附件2
            if(fan2!=-1&&j-cost[i]-cost[follows[i][1]]>=0){
                dp[i][j]=max(dp[i][j],dp[p][j-cost[i]-cost[follows[i][1]]]+value[i]+value[follows[i][1]]);
            }
            //全都买
            if(fan1!=-1&&fan2!=-1&&j-cost[i]-cost[follows[i][0]]-cost[follows[i][1]]>=0){
                dp[i][j]=max(dp[i][j],dp[p][j-cost[i]-cost[follows[i][0]]-cost[follows[i][1]]]+value[i]+value[follows[i][0]]+value[follows[i][1]]);
            }

        }
        p=i;
    }
    }
    return dp[p][money];//返回的是p，而不是m，因为是返回最后一个主件所在的那行的最后一个格子
}

//再写一个空间压缩版本
int dp1[32005];
int f1(){
    for(int i=1;i<=money;i++){
        dp1[i]=0;
    }
    for(int i=1;i<=m;i++){
        if(king[i]){
        for(int j=money;j>=cost[i];j--){//因为是类似01背包问题，空间压缩手段也是一样的，从右往左,知道j小于cost[i],
            //                                                                          也就是连主件都买不起，就停止了
            //只选主件
            if(j-cost[i]>=0){
            dp1[j]=max(dp1[j],dp1[j-cost[i]]+value[i]);
            }
            int fan1=-1,fan2=-1;
            if(fans[i]>=1)fan1=follows[i][0];
            if(fans[i]>=2)fan2=follows[i][1];//直接给fan1 fan2赋值follows的值，follows[i][1]就是附件的下标，下面可以不用写这么费劲
            //主件+附件1
            if(fan1!=-1&&j-cost[i]-cost[fan1]>=0){
                dp1[j]=max(dp1[j],dp1[j-cost[i]-cost[fan1]]+value[i]+value[fan1]);
            }
            //主件+附件2
            if(fan2!=-1&&j-cost[i]-cost[fan2]>=0){
                dp1[j]=max(dp1[j],dp1[j-cost[i]-cost[fan2]]+value[i]+value[fan2]);
            }
            //全选
            if(fan1!=-1&&fan2!=-1&&j-cost[i]-cost[fan1]-cost[fan2]>=0){
                dp1[j]=max(dp1[j],dp1[j-cost[i]-cost[fan1]-cost[fan2]]+value[i]+value[fan1]+value[fan2]);
            }
        }
    }
    }
    return dp1[money];
}

int main(){
    cin>>money>>m;
    int v,p,q;
    //因为下面要用到fans[]的值，初始化为0
    for(int i=1;i<=m;i++){
        fans[i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>v>>p>>q;
        if(q==0){
            king[i]=true;
            value[i]=p*v;
            cost[i]=v;
        }
        else{
            king[i]=false;
            value[i]=p*v;
            cost[i]=v;
            follows[q][fans[q]]=i;//表示q号主件中第fans[q]个附件的下标是i。上面已经初始化fans为0了，所以第一个附件就是第fans[q]=0
            fans[q]++;//第q号主件的附件数加一
        }

    }

    cout<<f()<<endl;
    cout<<f1()<<endl;
}