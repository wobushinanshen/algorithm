#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//一道数论构造题
//涉及：模运算同余，以及由a+b=0(mod g)，已知g反推b

//问题转换：转换为求一个数组ci,和一个数g，使得ai+k*ci可以被g整除
//为什么可以这样做？怎么想到的？
//首先，题目要gcd>1,但是gcd问题并不好求，这里就要思考转化问题，既然gcd>1都可以，那就可以找一个数(设为g)，使得所有操作完成后的数组中
//每个元素ai,都可以被g整除，那现在有两个问题，操作的标准是什么？g是多少？
//题目中的操作大致意思就是：对每个ai，最多可以进行k次操作，每次操作+0或者+k,设bi为操作后的ai,则ai<=bi<=ai+k*k
//也就是说对每个ai，可以选择加m个k(0<=m<=k)
//因此可以再构建一个数组c[i],表示每个ai选择加上多少个k，即b[i]=a[i]+c[i]*k
//那么b[i]需要满足b[i]=0(mod g),即b[i]可以被g整除
//现在就是要想，怎么构造c[i]和g才能让b[i]满足以上条件
//这里就是该题巧妙之处：试试让g=k+1，会怎样
//b[i]=0 (mod k+1),即a[i]+c[i]*k=0 (mod k+1)，
//反推出c[i],由乘法同余可得(a[i]+c[i]*k)%(k+1)=(a[i]%(k+1)+c[i]%(k+1)*k%(k+1)),这里的"k%(k+1)"是可以算出来的，等于-1
//于是乎便有了，a[i]=c[i] (mod k+1)
//所以c[i]=a[i]%(k+1)
//验证一下：a1=3 a2=4 k=2 c1=0 c2=1 则操作后b1=a1+c1*2=3,b2=a2+c2*2=6,可以被k+1(3)整除
//神奇欸，怎么想到呢……
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),c(n);
    //
    for(ll i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i]%(k+1);
        a[i]+=c[i]*k;
    }
    
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;//只要求一组数据时，把此行注释掉。
    while (T--) {
        solve();
    }
    return 0;
}