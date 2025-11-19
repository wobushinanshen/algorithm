#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n+5,vector<int>(n+5)),sum(n+5,vector<int>(n+5));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            sum[i+1][j+1]=a[i][j];//给sum加边界
        }
    }
    int max_=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=i;x<=n;x++){
                for(int y=j;y<=n;y++){
                    int temp=sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1];
                    max_=max(temp,max_);
                }
            }
        }
    }

    cout<<max_<<"\n";

}