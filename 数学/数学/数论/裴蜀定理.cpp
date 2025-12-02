#include<iostream>
using namespace std;
#include<algorithm>
//裴蜀定理：给定a,b并且gcd(a,b)为d,
//那么一定能找到一组(x,y),使得ax+by=d
//(x,y)是无限多组的
//重要理解：因为(x,y)是有很多组的，而d就是所以解中，最小的正整数
//推论1：存在(x,y)使得ax+by=1时，a b互质
//推论2：如果ax+by=c有解，那么c一定是d的整数倍
//推论3：对于多项，ax+by+cz+...=d,d也就是所有解中最小的正整数

//裴蜀定理例题：大意是给了一组数a b c d
//要求a*x1+b*x2+c*x3+d*x4...的最小正整数值，其中x1 x2...可以任取
//这就是重要理解的应用：无论是两个数a b 还是一组数，他们由a*x1+b*x2+...能够得出来的最小正整数就是他们的gcd
int n;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ans=gcd(abs(temp),ans);
    }
    cout<<ans<<endl;
}