#include<iostream>
#include<algorithm>
using namespace std;
int l,n,k;
int a[100005];
bool f(int min_){
    int m=0;//记录在每个固定答案下需要多少个路标，然后跟k比较
    //看能否满足条件
    for(int i=2;i<=n;i++){
        int temp=a[i]-a[i-1];
        if(temp>min_){
            m+=(temp%min_==0)?temp/min_-1:temp/min_;//向下取整
            //不确定的时候举个例子，画个图
        }
    }
    if(m<=k)return true;
    else return false;

}
int main(){
    cin>>l>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int a=1,b=l-(n-2);
    long long ans=0;
    while(a<=b){
        long long mid=(a+b)/2;
        if(f(mid)){
            ans=mid;
            b=mid-1;
        }
        else{
            a=mid+1;
        }
    }
    cout<<ans<<endl;

}