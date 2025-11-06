#include<iostream>
using namespace std;
long long f1(long long n){
    if(n==1)return 1;
    if(n==2)return 2;
    long long ans=0;
    long long lastlast=1;
    long long last=2;
    for(long long i=3;i<=n;i++){
        ans=lastlast+last;
        lastlast=last;
        last=ans;
    }
    return ans;
    
}
int main(){
    long long n;
    cin>>n;
    cout<<f1(n);

}