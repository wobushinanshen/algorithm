#include <bits/stdc++.h>
using namespace std;
//纸币问题1，依旧暴力递归入手，改记忆化，再dp
int value[1005];
int n, target;
//暴力递归，
//思路：跟爬楼梯很像,只不过爬楼梯对每个节点只有两种选择，要么是从前一级走一步，要么是从前两级走两步
//纸币问题每个节点有n个选择，需要for循环来实现对应操作

int f1(int mon){
    if(mon<0)return -1;//返回-1，代表无解
    if(mon==0)return 0;
    int res=INT_MAX;
    //for循环的含义：
    //当前的mon值，对所有value都试一遍，
    //可能有的value是对应是无解的，只要找到有解中的最小值即可
    //也有可能所有value都是无解的，这就说明当前的mon就是无解的,返回题目要求的值-1
    //不要将该思想推广到所有子树，就在当前这个子树去想，就很好理解
    //当前这棵子树就是，头节点是mon，子节点就是i个mon-value[i]
    for(int i=1;i<=n;i++){
        int temp=f1(mon-value[i]);//先算出子问题
        if(temp!=-1){//判断子问题是否有解
        res=min(temp,res);
        }
    }
    return res!=INT_MAX?res+1:-1;
    //res=INT_MAX说明当前的mon对应是无解的
    //那就返回-1(一般是题目要求返回的数)
    //有解就返回res+1，因为res对应的是mon-value[i]的答案，要想返回mon的答案，就是加1嘛(记得要时刻清楚答案的含义)

}

//改记忆化，初始化不可以等于-1，因为-1已经有了含义，是指无解的情况
//基本上和递归一样：加了个memo表，在递归的基础上加了一个判断以及给memo表赋值的操作
const int INF=10000;
int memo[10005];
int f2(int mon){
    if(mon<0)return -1;
    if(mon==0)return 0;
    if(memo[mon]!=-2)return memo[mon];
    int res=INF;
   
    for(int i=1;i<=n;i++){
        int temp=f2(mon-value[i]);
        if(temp!=-1){
        res=min(temp,res);
        }

    }
    memo[mon]=res!=INF?res+1:-1;
    return res!=INF?res+1:-1;
}

//再改dp
//还是先明确dp数组的含义：dp[mon]指的是凑出mon需要的最少纸币数
//状态是：mon;  选择：选哪个value[i];    初始化：dp[0]=0
//状态转移方程，主问题与子问题之间的关系是：
int dp[10005];
int f3(int mon){
    dp[0]=0;//初始base case
    for(int now=1;now<=target;now++){
        for(int j=1;j<=n;j++){
            //在value数组里面选择，在now-value[j]的情况下，选择dp[now-value[j]]最小的
            //如何实现上述操作：用for循环遍历一次value数组，用min选出最小的子问题
            //还需注意：dp[now-value[j]]必须是有解的，
            //怎么确定是否有解呢：最初的时候先给dp设初始值为-INF,如果后面用到的子问题对应的dp值!=INF
            //就说明有解，否则，说明该位置无解
            if(now-value[j]>=0&&dp[now-value[j]]!=INF){
                dp[now]=min(dp[now-value[j]]+1,dp[now]);
            }

        }
        
    }
    return dp[mon]==INF?-1:dp[mon];
}

signed main() {
    cin>>n>>target;
    for(int i=1;i<=n;i++){
        cin>>value[i];
        
    }
    //memo表的初始化就这样写个循环，包不会错的
    for(int i=1;i<=target;i++){
        memo[i]=-2;
    }
    //
    for(int i=1;i<=target;i++){
        dp[i]=INF;
    }
    cout<<f1(target)<<"\n";
    cout<<f2(target)<<"\n";
    cout<<f3(target)<<"\n";









}
