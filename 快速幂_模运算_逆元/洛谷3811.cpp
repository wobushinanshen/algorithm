#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long n,p;
    cin>>n>>p;
    vector<long long>inv(n);
    inv[1]=1;
    cout<<1<<endl;
    for(int i=2;i<=n;i++){
        inv[i]=((p-p/i)*inv[p%i]%p);
        cout<<inv[i]<<endl;
    }
}