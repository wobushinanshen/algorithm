#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);//辗转相除法
}
//21 7 -->gcd(21,21%7)-->gcd(7,0)
//17 68 -->gcd(17,17%68)-->gcd(17,17)-->gcd(17,0)
int main(){
    int a=3,b=6;
    cout<<"gcd:"<<gcd(a,b)<<endl;//最大公约数
    cout<<"lcm:"<<a/gcd(a,b)*b<<endl;//最小公倍数:其中一个数除以gcd再乘上另外一个数,a*b/gcd(a,b)
    //也就是说：a*b=gcd(a,b)*lcm(a,b)
    
}