#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b,long long p){
    long long res=1;
    long long base=a;
    while(b){
        if(b&1){
            res=res*base%p;
        }
        base=base*base%p;
        b>>=1;
    }
    return res%p;
}
//费马小定理
void solve() {
    long long n,p;
    cin>>n>>p;
    for(long long i=1;i<=n;i++){
        cout<<binpow(i,p-2,p)<<endl;
    }

}
//线性递推
void solve2(){
    long long n,p;
    cin>>n;
    cin>>p;
    vector<int>inv(n);
    inv[1] = 1;
    cout<<inv[1]<<endl;
    for(long long i = 2; i <=n; ++ i){
        inv[i] = (p - p / i) * inv[p % i] % p;
        cout<<inv[i]<<endl;
    }
   
}
//阶乘求逆元--也有线性递推
void solve3(){

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;//只要求一组数据时，把此行注释掉。
    while (T--) {
        solve2();
    }
    return 0;
}