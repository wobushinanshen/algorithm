#include<iostream>
#include<map>
using namespace std;
long long a[200005];
map<int,int>b;

int main(){
    long long n,c;
    cin>>n>>c;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
        a[i]-=c;

    }
    long long res=0;

    for(int i=0;i<n;i++){
        res+=b[a[i]];
    }
    cout<<res;
}