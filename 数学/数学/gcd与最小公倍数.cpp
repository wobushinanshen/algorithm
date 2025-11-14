#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);//辗转相除法
}
int main(){
    int a=3,b=6;
    cout<<"gcd:"<<gcd(a,b)<<endl;//最大公约数
    cout<<"lcm:"<<a/gcd(a,b)*b<<endl;//最小公倍数:其中一个数除以gcd再乘上另外一个数
    
}