#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
//要求什么：最大和的最小值
//答案范围：[数组中最大值,数组和]  (注意单位千万不能写漏或写多)
//条件：分为m段
//单调性关系：答案越大，越容易满足条件
int n,m,max_=0;
int a[100005];
ll sum=0,ans;
//判断是否满足条件的逻辑：先算出每个固定答案需要分成
//k段涵盖所有数组，再用k与m比较，k<=m则true
//另外，如果数组里面存在某个数大于当前的固定答案，直接返回false
bool f(ll num_parts){
    ll temp=0;
    ll k=1;//一开始给k赋值0了，WA了
    //因为最后一段总是会漏掉，比如num_parts=4  数组：2 3 1 4 如果k=0，最后k会变为2，但是其实是3段，再试一个：2 3 1 4 2
    //不管最后是>num_parts,还是<=num_parts,都会漏掉一段
    for(int i=1;i<=n;i++){
        if(a[i]>num_parts)return false;
        else{
            temp+=a[i];//累加一段区间和
            if(temp>num_parts){
                k++;
                temp=a[i];//如果加上最后的一个a[i]使区间和大于num_parts，temp值重置为当前的a[i]
            }

        }
    }
    return k<=m?true:false;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        max_=max(max_,a[i]);
    }
    ll l=max_,r=sum;
    while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}