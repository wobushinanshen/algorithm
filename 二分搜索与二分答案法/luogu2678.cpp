#include<iostream>
using namespace std;
//跳石头：
//首先要自信点，二分模板是没有问题的
//读题，要求的是最短跳越距离的最大可能值，条件是至多可以移走M个石头
//二分答案范围：1-L
//单调性关系：距离取得越大，需要移动的石头越多，也就是满足条件的情况下，即移走石头数<=M,可以将距离往大取，即向右边二分(l=mid+1);
//f函数：对于每次传入的固定的答案，要判断是否满足条件：首先计算出需要移动多少个石头才能满足当前的答案(即距离)，然后将需要的石头数和m比较即可
//
//其实找答案范围不难，判断单调性也不难，重点在check函数中的判断条件，需要记住，传入的是一个固定的答案，你要判断这个答案是否可行的话，
//你最后一定是要跟题目给定的条件来比较的是吧，所以呢，你的目标就是求与题目条件相同性质的东西，比如这题就是计算出每个固定答案需要的石头数。
int stones[500005];
int L,n,m;
bool f(int mid){
    int x=0;
    int last=0,now=0;
    for(int i=1;i<=n+1;i++){
        now=stones[i];
        if(now-last<mid){
            x++;
            
        }
        else{
            last=stones[i];
        }
        
    }
    if(x<=m)return true;
    else return false;
}
int main(){
    
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>stones[i];
    }
    stones[0]=0;
    stones[n+1]=L;
    int l=1,r=L;
    int ans=0;
    while(l<=r){
        long long mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    
    }
    cout<<ans<<"\n";
}