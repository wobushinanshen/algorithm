#include<iostream>
using namespace std;
#include<vector>
//二维差分例题

int main(){
    int n,m,a,b,c,d;
    cin>>n>>m;
    vector<vector<int>>arr(1005,vector<int>(1005));//用vector避免初始化出问题
    while(m--){
        cin>>a>>b>>c>>d;
        arr[a][b]++;
        arr[c+1][d+1]++;
        arr[c+1][b]--;
        arr[a][d+1]--;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+arr[i][j];

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}