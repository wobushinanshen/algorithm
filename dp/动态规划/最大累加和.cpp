#include<iostream>
#include<algorithm>
using namespace std;
//给定一个数组，找到累加和最大的一个子数组
//这是一个经典的dp问题，叫做kadane算法说是。
int main(){
    int n;
    cin>>n;
    int a[10086];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dp[10086];
    dp[1]=a[1];
    //明确dp数组的定义
    //dp[i]；指的是以i位置的数作为结尾，往左能延伸出的最大累加和
    //状态转移方程：dp[i]=max(dp[i-1]+a[i],a[i]);
    int ans=a[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
        ans=max(dp[i],ans);
    }
    
    cout<<ans<<endl;
    //可以举个例子试试，很清晰的
    //比如3 1 -9 2 4
    //dp[1]=3,因为给dp[0]设置了0
    //dp[2]=4,dp[3]=-9+dp[2],这里可以发现只要dp[i-1]大于0，就……



    //还可以空间压缩，因为没有必要开一个dp数组
    //准备一个pre
    int pre=0,res=0;
    for(int i=1;i<=n;i++){
        //如果前面最大区间和大于0，
        if(pre>0){
            pre=a[i]+pre;
            res=max(pre,res);
        }
        //如果前面的最大区间和都小于0了，就没必要再往前面延申了
        else{
            pre=a[i];
            res=max(a[i],res);
        }
        
    }
    cout<<res<<endl;
}