#include<iostream>
#include<vector>
using namespace std;
//这题应用了异或不进位相加的性质，以及应用异或将低位数全部变为1
//a^b的二进制最大位数只能小于等于a,b中二进制的最大位数
//因为异或就是不进位相加，既然是不进位，那么就不可能会产生更大的二进制数

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<"\n";
        return;
    }
    int max_a=0,max_b=0;
    //利用按位与操作，求出a b的最大二进制位数
    for(int i=0;i<31;i++){
        if(1<<i&a){
            max_a=i;
        }
        if(1<<i&b){
            max_b=i;
        }
    }
    //比较
    if(max_a<max_b){
        cout<<-1<<"\n";
        return;
    }
    //这里题解用了一个巧妙地方法：先补全a的低位，再去操作
    //怎么说呢，因为a的最高位一定都覆盖了b
    //如果有一个二进制数全为1，且最高位就是a的最高位的数c
    //那么直接就着c来操作，使其变为b，是不是就很简单
    //只需要将b中非0的位置异或一下，
    //比如a--1001,b--0110,则c--1111
    //那么答案就是0001,1000,再加上从a到c需要的操作，就是最终答案
    //即0010,0100,0001,1000
   
    vector<int>ans;
    //补全低位1
    for(int i=0;i<31;i++){
        if((1<<i<=a)&&((a&1<<i)==0)){
            a^=(1<<i);
            ans.push_back(1<<i);
        }
    }
    //
    for(int i=0;i<31;i++){
        if((1<<i<=a)&&((b&1<<i)==0)){
            ans.push_back(1<<i);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";

    }
    
    cout<<"\n";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}