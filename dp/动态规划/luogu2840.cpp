#include <bits/stdc++.h>
using namespace std;
//纸币问题2：不问最少纸币数，改成方案数了
//思路：当前mon值的结果等于，每个mon-value[i]之和(其中mon-value[i]>=0才会有结果)
//暴力递归入手，改记忆化，再改dp
int n,target;
int value[10005];

//base case到底返回什么呢，为什么mon<0的时候，对于纸币问题1求最少纸币数的时候返回-1
//这里又返回0呢
//base case返回的就是最小子问题的答案，而两个纸币问题1和纸币问题2
//为什么不同，就是因为他们要求的答案不同

//首先纸币问题1要求答案是凑出某个值的最少纸币数，
//当mon=0的时候，返回0，指的是用0张纸币嘛，这跟其他答案的性质一样啊
//当mon<0的时候，返回-1是题目要求的,即无解的时候返回-1(对返回什么并没有说一定是-1，是根据题意的)
//

//对于纸币问题2，要求的是凑出某个值的方案数
//那当mon=0的时候，答案不就是1种吗，就是"什么也不选"这一种方案
//这跟答案的性质也是一样的
//mon<0的时候，返回0，也就是0种方案可以实现，
//这不也跟其他答案的性质一样吗

//所以遇到base case要返回什么，就要想，在base case情况下，题目要求的是什么(很容易理解，只是别绕进去了)
long long f1(int mon){

    if(mon==0)return 1;//base case可以不是target的边界噢，边界是1，但是base case是0,
    if(mon<0)return 0;
    long long res=0;
    for(int i=1;i<=n;i++){
        int temp=mon-value[i];
        
        res+=f1(temp);
        res%=1000000007;
        
    }
    return res%1000000007;
}

//改记忆化搜索
long long memo[10005];
long long f2(int mon){
    if(mon==0)return 1;//base case可以不是target的边界噢，边界是1，但是base case是0,
    if(mon<0)return 0;
    if(memo[mon]!=-66)return memo[mon];
    long long res=0;
    for(int i=1;i<=n;i++){
        int temp=mon-value[i];//这里就不需要像纸币问题1一样判断temp是否大于0，因为temp小于0的时候，上面的base case会返回0，跟没加是一样的结果
        res+=f2(temp);              //当然也可以把if语句保留，然后删掉上面的mon<0的if语句。
        res%=1000000007;
        
    }
    memo[mon]=res%1000000007;
    return res%1000000007;
}


//改dp
long long dp[100005];
//这里说一下，其实dp函数就不用写参数了，因为不用递归，是相当于把结果从底到顶全部算出来之后再取最顶部的结果
//当然，如果要求中间的某个结果，当我没说，所以还是习惯性地给dp函数也弄个参数吧
//明确状态：每个值； 选择：分别将当前mon值减去value中的各个元素的结果作为子问题   以及初始化：dp[0]=1
//状态转移方程
long long f3(int mon){
    dp[0]=1;
    for(int now=1;now<=target;now++){
        for(int i=1;i<=n;i++){
            if(now-value[i]>=0){//因为最小子答案是在大于等于0的时候才会有结果，
                int temp=dp[now-value[i]];
                dp[now]+=temp;
                dp[now]%=1000000007;
            }
        }
    }
    return dp[mon]%1000000007;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>target;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    for(int i=1;i<=target;i++){
        memo[i]=-66;
    }

    cout<<f1(target)<<"\n";
    cout<<f2(target)<<"\n";
    cout<<f3(target)<<"\n";
}