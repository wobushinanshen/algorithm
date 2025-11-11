#include<iostream>
using namespace std;
//输入两个数，求他们拼接后的数的mod9的结果
//如，2 5--->求2345%9     2 8--->求2345678%9
void solve1(){
    long long l,r;
	cin>>l>>r;
	long long ans=0;
	for(;l<=r;l++){
		long long temp=l%9;        
	    ans+=temp;
    }
	cout<<ans%9<<endl;  
}
//因为任何10的倍数mod9都是1，现在比如输入2 5
//即2345mod9的值，那2000mod9是不是等于2%9*1000*9，又因为1000%9=1，那是不是就等于2mod9啊
//因为1000%9就等于1，这里是乘法同余知识，
//那2345mod9可以拆解成2000 300 40 5 mod9吧，则同理可以知道
//等于2%9+3%9+4%9+5%9，这不就是2-5分别mod9吗
//因此一个循环搞定，但是TLE需要优化，
void solve2(){

//又根据加法同于原理以及等差数列求和公式
//不难想到，可以先计算2-5的和，再取模
//然而等差数列求和有个分母2呀，这怎么办
//难道要用逆元吗，注意9不是质数哦，逆元无效
//其实这跟AK杯C题很像，仔细观察，会发现分子一定是2的倍数
//因为要么(l+r)是偶数，要么r-l+1是偶数
//所以，只需要做一个判断，然后偶数项先/2，再取模和另外一项相乘

	long long l,r,ans;
	cin>>l>>r;
	long long x,y;
	long long temp;
	x=(l+r);
	y=(r-l+1);
	if(x%2==0){
		temp=x/2;//x是偶数，能2被整除
		ans=(temp%9*y%9)%9;//分别取模再相乘，避免溢出
	}
	else{
		temp=y/2;
		ans=(x%9*temp%9)%9;
	}
	cout<<ans<<endl;
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve2();
	}

}