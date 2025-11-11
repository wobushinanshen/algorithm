#include<iostream>
#include<vector>
using namespace std;
//模板题：线性递推求逆元，注意不要用endl，会TLE

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long n,p;
    cin>>n>>p;
    vector<long long>inv(n);
    inv[1]=1;
    cout<<1<<"\n";
    for(int i=2;i<=n;i++){
        inv[i]=((p-p/i)*inv[p%i]%p);
        cout<<inv[i]<<"\n";
    }
}