#include<bits/stdc++.h>
using namespace std;
//扩展欧几里得求逆元(条件是a和给定的mod数互质)
//设在mod b的意义下，a的逆元是x,即a=1/x (mod b)
//逆元的作用不再多说,多用于除法同余方程
//再说一下同余方程：就是余数相等的意思，可写成a = b(mod p),表示a b对p取余数后结果相同
//
//怎么求mod b意义下a的逆元x？
//x=1/a (mod b)-->ax%b=1
//即ax-?b=1(由前面知识可知)
//欸？这种形式很眼熟，就是裴蜀定理的式子呀，如果就看作ax+by=gcd的形式，那现在gcd等于1，说明a,b互质
//扩欧仅需要知道a,b的值，就可以求出一组(x,y)，然后只需要x的值就行了，
//x可能为负数，所以最后要对x进行：(x%b+b)%b,即可保证x为正，同时又是有效的a的逆元
int x,y,px,py;
void exgcd(int a,int b){
    if(b==0){
        x=1;
        y=0;
    }
    else{
        exgcd(b,a%b);
        px=x;
        py=y;
        x=py;
        y=(px-py*(a/b));
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    exgcd(a,b);
    cout<<(x%b+b)%b<<endl;

}