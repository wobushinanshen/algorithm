#include<iostream>
#include<algorithm>
using namespace std;
int a[10005][1005];
int r;
int dfs(int i,int j){
    if(i==r)return a[i][j];
    return max(dfs(i+1,2*(j-1)+1),dfs(i+1,2*(j-1)+2));
}
int main(){
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    cout<<dfs(1,1);

}

