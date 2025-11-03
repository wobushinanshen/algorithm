#include<iostream>
using namespace std;
long long binpow1(int a,int b,int p){
    long long res=1;
    long long base=a;
    while(b){
        //b是奇数才更新res,这是因为奇数的二进制表示中第一位是1
       if(b%2==1){//或者写成b&1
        res=res*base%p;
       }
       base=base*base%p;
       //b除以2相当于二进制中右移1位
       b/=2;//也可以写成b>>=1,表示右移一位。
    }
    return res;
}
long long binpow2(int a,int b,int p){
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

//上面运用了快速幂和模运算的性质
int main(){
    int a,b;
    cin>>a>>b;
    int p;
    cin>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<binpow1(a,b,p)<<endl;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<binpow2(a,b,p)<<endl;
}