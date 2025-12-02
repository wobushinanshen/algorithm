#include<iostream>
using namespace std;
//质数判断
//特殊情况：1 2 偶数
//对于非特殊情况：从3开始步长为2，一直到sqrt(n)，如果中途出现某个i，使得n%i==0，则return false
bool isPrime(int n){
    if(n==1)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i=3;i*i<=n;i+=2){//i很大的时候，改long long 防止溢出
        if(n%i==0)return false;

    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isPrime(n)){
        cout<<n<<"is prime";
    }
}