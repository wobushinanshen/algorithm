#include<iostream>
using namespace std;
//这是一个小引入：给你一个数，让你从高到低打印出这个数的m位二进制形式
void solve(){
    int n=101;//这个数是101
    int m=9;//要求打印出9位二进制
    int temp=n;
    for(int p=m;p>=0;p--){
        if(1<<p<=temp){
            temp-=(1<<p);
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
}
//这就是倍增的思想了
int main(){
    solve();
}