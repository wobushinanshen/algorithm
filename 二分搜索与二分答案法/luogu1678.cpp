#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
vector<int>sc,st;
ll m,n,l,r;
ll f(ll s){
    l=0,r=m-1;//!!!多测不重置，调试泪空空。
    //注意如果l，r定义的是全局变量，并且这个二分查找函数
    //会被用到多次，一定要重置
    ll min_=100005;
    while(l<=r){
        ll mid=(l+r)/2;
        if(sc[mid]>s){
            r=mid-1;
            min_=min(min_,abs(s-sc[mid]));
            
        }
        else if(sc[mid]<s){
            l=mid+1;
            min_=min(min_,abs(s-sc[mid]));
        }
        else{
            min_=0;
            break;
        }

    }
    
    return min_;
}
int main(){
    cin>>m>>n;
    ll temp=0;
    for(ll i=0;i<m;i++){
        cin>>temp;
        sc.push_back(temp);
    }
    for(ll i=0;i<n;i++){
        cin>>temp;
        st.push_back(temp);
    }
    sort(sc.begin(),sc.end());
    sort(st.begin(),st.end());
    
    l=0;
    r=m-1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=f(st[i]);
    }
    cout<<ans<<"\n";
}