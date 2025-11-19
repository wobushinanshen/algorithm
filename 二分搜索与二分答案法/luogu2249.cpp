#include<iostream>
using namespace std;
int a[1000010];
int main(){
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    int target=0;
    while(t--){
        cin>>target;
        int l=1,r=n;
        while(l<r)//这里不要带等于号，不然死循环(很多次了)
        {
        long long mid=(l+r)/2;
        if(target>a[mid]){
            l=mid+1;

        }
        else if(target<a[mid]){
            r=mid-1;

        }
        else{
            r=mid;

        }
        
    
    }
    if(a[r]==target)cout<<r<<" ";
        else cout<<"-1"<<" ";
    }
}