#include<iostream>
using namespace std;
//现在要算：((a+b)+(a-c)*(b-c))%p  (保证abc不超过int范围)
//先演示不使用同余原理的
long long f1(long long a,long long b,long long c,long long p)
{
    long long o1=a+b;
    long long o2=a-c;
    long long o3=b-c;
    long long res=(o1+o2*o3)%p;
    return res;
}
//使用同余原理
long long f2(long long a,long long b,long long c,long long p){
    long long o1=(a+b)%p;
    long long o2=(a-c+p)%p;//减法同余加个p
    long long o3=(b-c+p)%p;
    long long res=(o1+o2*o3)%p;//结果也同余一下
    return res;
}
int main(){
    //对于取模运算，有以下性质：
    //1. (a + b) % p = ((a % p) + (b % p)) % p
    //2. (a - b) % p = ((a % p) - (b % p) + p) % p
    //3. (a * b) % p = ((a % p) * (b % p)) % p
    //只适用于加减乘
    //题目结果很大的时候通常用结果mod一个数，以代替结果
    //既然最后要取mod，那么利用取模运算的性质，可以在每一步计算后都对结果取模
    //比如我要算一个阶乘
    int p=998244353;
    long long a,b,c;
    a=1000000000;
    b=923133124;
    c=71234123;
    cout<<"the result of f1:"<<endl;
    cout<<f1(a,b,c,p)<<endl;
    cout<<"the resylt of f2:"<<endl;
    cout<<f2(a,b,c,p)<<endl;
    //运行可以发现同余的结果与不使用同余的结果是一样的，如果式子更复杂，中间的某个计算过程或者某个结果会超出数据类型范围
    //那么此时只有使用同余才能得到正确结果
 }