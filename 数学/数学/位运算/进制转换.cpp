#include <bits/stdc++.h>
using namespace std;
//B：今天系统学习一下进制转换
//A：哎，这东西我已经回了，不就是求商取余吗。
//B：那是十进制转其他进制，况且16进制的字母你怎么处理，还有其他进制转十进制，其他进制互相转换你会了吗。
//A：错了，我不会，orz
//B：十进制转其他进制就是求商取余，另外十六进制中10-15分别用A-F表示，在求余后用一个判断语句
//   判断是否出现大于10的余数，然后分别用A-F表示。

//   其他进制转十进制：这个也很简单，以二进制为例，(1011)=(1*2^3+0*2^2+1*2^1+1*2^0);
//   就这个公式,同样的，十六进制的A-F字符需要判断语句

//   还有其他进制的互相转换：可以先转成十进制，再转其他进制
//   当然也可以直接转

//1、十进制转各种进制
string solve1(int n,int base) {
   
    string res;
    while(n>0){
        int rem = n%base;
        if(rem<10){
            res+='0'+rem;//补充一下'0'+num ---->数字转字符，如果num<10，如数字2会转换为字符形式的'2'
        }
        else{
            res+='A'+(rem-10);
        }
        n/=base;
    }
    reverse(res.begin(),res.end());
    return res;

}

//2、各进制转十进制
int solve2(string s,int base){
    int len=s.size();
    int res=0;
    for(int i=len-1;i>=0;i--){
        if(s[i]-'0'<10){
            int temp = pow(base,len-1-i)*(s[i]-'0');
            res+=temp;
        }
        else{
            int num = s[i]-'A'+10;
            int temp1=pow(base,len-i-1)*num;
            res+=temp1;
        }

    }
    return res;
}
signed main() {
    int n,base;//n是十进制，base指要转换的进制。（保证n不为负数）
    cin>>n>>base;
    string res1 = solve1(n,base);
    cout<<res1<<endl;
    string s;
    int base1;
    cin>>s>>base1;
    int res2 = solve2(s,base1);
    cout<<res2<<endl;
}