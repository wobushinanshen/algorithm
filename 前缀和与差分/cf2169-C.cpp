#include<iostream>
#include<algorithm>
using namespace std;
//将区间操作转换：本来是[l,r]都替换为l+r
//那么对区间求和之后就是：(l+r)*(r-l+1)，
//(r-l+1)是项数，(l+r)可以写成(2l+2r)*(1/2)
//整个公式就变成:(2*l+2*r)*(r-l+1)*(1/2),这是等差数列求和公式，首项是2l,末项是2r
//最后将整个问题转换为求b数组中累加和最大的子数组
//这个问题可以用kadane算法实现，是很经典的dp问题
//当然，用前缀和也是可以的
void solve(){
    int n;
    cin>>n;
    int a[200005];
    int b[200005];
    long long total=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        total+=a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=2*i-a[i];
    }//记录增量，每个位置的增量构成数组b
    long long pre_max=0,res=0;
    for(int i=1;i<=n;i++){
        if(pre_max>0){
            pre_max+=b[i];
            res=max(res,pre_max);
        }
        else{
            pre_max=b[i];
            res=max(res,pre_max);
        }
        
    }
    cout<<res+total<<"\n";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

}