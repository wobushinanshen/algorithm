#include<iostream>
#include<algorithm>
using namespace std;
//洛谷1216，经典题目，展示从暴力递归到记忆化搜索，再到递推(即dp)来解决这个问题
int a[10005][1005];
int r;

//暴力递归:
//最大的问题就是怎么写出递归的问题
//首先明确要求什么，因为要返回最大值，所以函数类型为int
//然后拆分问题，当前位置最大和就等于子叶中的最大和加上当前位置的数，怎么才可以表示成这样呢
//只需将数组定义成a[i][j]，来表示第i行，第j个
//最后，确定base case，即什么时候终止递归，很明显
//当递归到最后一层的时候，没有下一层了，就开始返回，此时最大和就是当前位置的数，即a[i][j]
//记住不要试图去深究：只需要取最简单的一个子树来进行分析，不要去推，不要去推，不要去推！
int f(int i,int j){
    if(i==r)return a[i][j];//
    return a[i][j]+max(f(i+1,j),f(i+1,j+1));
}

//加上备忘录：变记忆化搜索
//为什么可以记录这个答案？回想一下递归的压栈过程，是最左边
//的子树完成后，再开始右边，也就是在左边子树到底后，开始回去的时候，答案才开始显现
//这时候，记录下每个位置对应的答案(当然每个位置的答案的含义是指前i个位置所带来的结果)，不必理解
//memo初始化-1
int memo[10005][10005];
int f1(int i,int j){
    if(i==r)return a[i][j];
    if(memo[i][j]!=-1)return memo[i][j];
    int res=a[i][j]+max(f1(i+1,j),f1(i+1,j+1));
    //先求出答案再记录到memo表里
    memo[i][j]=res;
    return res;
}

//改递推，即dp,从底到顶
//既然我们可以自顶向下，再去回溯的到答案，就一定可以直接从底往顶
//dp步骤：明确状态，选择，初始条件，写出转移方程
//for(int i ; i<){
//  for(int j ; j< ){
//              
//          }
//              }
int dp[10005][10005];//dp数组的含义是i行j列位置上的答案(即最大和)
int f2(int x,int y){
    
    for(int i=r;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==r){
                dp[i][j]=a[i][j];//初始化(base case)
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
            }
        }

    }
    return dp[x][y];
}
int main(){
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            memo[i][j]=-1;
        }
    }
    cout<<f(2,2)<<"\n";//输入任何位置都应该返回正确结果，因为数组的定义就是某个位置的结果
    cout<<f1(2,1)<<"\n";
    cout<<f2(3,1);
}   

