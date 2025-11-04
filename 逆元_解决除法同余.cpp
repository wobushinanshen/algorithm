#include<iostream>
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
    return res;
}
int main(){
    //A:除法无法使用同余，怎么办?
    //B:用逆元啊
    //A；逆元？是什么东西
    //B；先告诉你结论，假设b1是b的逆元，则(a/b)mod p = (a*b1)mod p,现在变成乘法了，就可以用同余了
    //A；太神奇了，那要怎么求b的逆元b1呢？
    //B：很简单，b1=b^(p-2),这里就可以用上之前学的快速幂来算逆元啦
    //A:好耶，我要试试
    //B：等等，还有一件事，记得p要为质数并且b与p要互质，即b不能是p的倍数
    long long a=26,b=13,p=11;
    long long binv=binpow(b,p-2,p);
    cout<<(a/b)%p;
    long long res2=(a%p*binv)%p;//这里因为binv已经再求的时候对p取过模了
    cout<<res2<<endl;

}