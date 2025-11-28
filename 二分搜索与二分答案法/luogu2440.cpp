#include<iostream>
using namespace std;
#include<algorithm>
int n,k;
int a[100005];
//对于每个固定答案，判断是否满足：能够在所有木材中凑够k根max_len长度
//的木材
bool f(int max_len){
    int m=0;
    for(int i=1;i<=n;i++){
        m+=(a[i]/max_len);
    }
    if(m>=k)return true;
    else return false;
}
int main(){
    cin>>n>>k;
    int max_=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    //答案范围
    int l=1,r=max_;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid+1;

        }
        else{
            r=mid-1;
        }

    }
    cout<<ans<<endl;


}