#include<iostream>
using namespace std;
#include<vector>
// <------------------------------->

// 这里介绍三种求逆元的方法，它们分别适用于不同的情况
//1、费马小定理
//2、线性递推
//3、阶乘求逆元
// <------------------------------->
//费马小定理求逆元
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
    return res;
}

int main(){
    //A:除法无法使用同余，怎么办?
    //B:用逆元啊
    //A；逆元？是什么东西
    //B；先告诉你结论，假设b1是b的逆元，则(a/b)mod p = (a*b1)mod p,现在变成乘法了，就可以用同余了
    //A；太神奇了，那要怎么求b的逆元b1呢？
    //B：很简单，有个叫做费马小定理：b1=b^(p-2) mod p,这里就可以用上之前学的快速幂来算逆元啦
    //A:好耶，我要试试
    //B：等等，还有一件事，记得p要为质数并且b与p要互质，即b不能是p的倍数，还有a/b可以整除，
    // 所以如果要计算a/b，那么就要保证mod是质数，b和mod互质，a/b可以整除这三个条件。
    long long a=26,b=13,p=11;
    long long binv=binpow(b,p-2,p);//b的p-2次方mod p
    cout<<(a/b)%p;
    long long res2=(a%p*binv)%p;
    cout<<res2<<endl;


    //A：哇，但是我在洛谷3811 TLE了，除了费马小定理，还有其他做法吗？
    //B：有的兄弟有的，这就是线性递推求逆元,专门求1到n对于p的逆元（注意p也要为质数）
    //A: 好像有点抽象了……
    //B：不用纠结为什么,只需要知道如果要求1-n的逆元，就可以用！
    //原理就是通过上一个数的逆元可以推出当前数的逆元，不用管为什么,因此就不需要每个数都通过快速幂
    //又因为1的逆元就是1，所以从1一直迭代求1-n的逆元
    
    int n;
    cin>>n;
    cin>>p;
    vector<int>inv(n);
    inv[1] = 1;
    for(int i = 2; i <=n; ++ i)
        inv[i] = (p - p / i) * inv[p % i] % p;//记住这个公式
    for(int i=1;i<=n;i++){
        cout<<inv[i]<<endl;
    }


    //A：我又遇到一个问题了，组合数怎么去mod p，下面的分母怎么求逆元--洛谷3717
    //B：首先确定公式是：n!/(m!*(n-m)!),没错吧。
    //A：对
    //B：然后只需要求m!和(n-m)!的逆元即可，这是阶乘求逆元
    //A：那怎么求
    //B：别急着求逆元，先求一个阶乘表，fac[],其中fac[i]表示i!在mod意义下的余数
    //A：噢，这个我会，可以用乘法逆元
    int LIMIT=1000;//LIMIT是最大阶乘数
    vector<long long>fac(LIMIT+1);
    fac[1]=1;
    for(int i=2;i<=LIMIT;i++){
        fac[i]=(i*fac[i-1])%p;
    }
    //A：然后呢？
    //B：只需求最大可能值的阶乘的逆元，然后线性递推出其他1到LIMIT-1阶乘的逆元，具体实现如下
    vector<long long>inv(LIMIT+1);
    inv[0]=1;
    inv[LIMIT]=binpow(fac[LIMIT],p-2,p);
    for(long long i=LIMIT-1;i>=0;i--){
        inv[i]=(inv[i+1]*(i+1))%p;
    }
    //A:这就可以了？为什么
    //B：i阶乘的逆元等于i+1阶乘的逆元乘上modp意义上的i+1,再去mod p,这个应该不难理解吧
    //B：如果不理解，就记住inv[i]=(inv[i+1]*(i+1))%p
    //A: ……
    //A:让我试试3717
    //A：哎，终于AC了，花了一个上午的时间
    //A：让我来总结一下阶乘求逆元的步骤：
    //   首先，先求一个阶乘表fac：fac[0]=1,fac[i]=fac[i-1]*i%p;
    //   然后，计算最大值的逆元，这里需要写一个binpow快速幂，然后代入inv[N]=binpow(fac[N],p-2);
    //   最后通过这个inv[N]值，线性递推1到N-1的所有逆元，inv[i]=inv[i+1]*(i+1)%p;
    //   现在我们就有了一个阶乘表和一个逆元表
    //   要求什么组合数就很简单了吧，fac[n]*inv[m]%p*inv[n-m]%p;




}