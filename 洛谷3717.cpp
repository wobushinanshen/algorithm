#include<iostream>
using namespace std;
typedef long long ll;
ll p=998244353;
ll T,N;
ll fac[5000005],inv[5000005];
//费马小定理用快速幂求逆元，这题只用来求N！的逆元
long long binpow(long long a,long long b){
    long long res=1;
    long long base=a;
    while(b){
        if(b&1){
            res=res*base%p;
        }
        base=base*base%p;
        b>>=1;
    }
    return res;
}
void solve(){

    cin>>T>>N;
    fac[0]=1;
    //预处理阶乘：其中fac[i]表示i的阶乘mod p
    for(int i=1;i<=N;i++){
        fac[i]=(i*fac[i-1])%p;
    }
    inv[N]=binpow(fac[N],p-2);//先计算出最大数N！的逆元
    //这里通过最大数的逆元，线性递推出0到N-1的逆元，于是我们得到了inv[N]
    for(int i=N-1;i>=0;i--){
        inv[i]=(inv[i+1]*(i+1))%p;//这是线性递推公式
        //啥？什么原理？
        //不清楚，不过大概就是，i+1！的逆元*mod p意义下的i+1，再去mod p就是i！的逆元
        //…………不懂不懂，记结论吧。
    }
    int ans = 0;
	while(T--) {
		int n, m; 
        cin >> n >> m;
		ll tmp = fac[n] * inv[m] % p * inv[n - m] % p;//这里就是计算了：n!*inv[m!]*inv[(n-m)!]
		ans ^= tmp;//按位异或
	}
	cout << ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    
}