#include<iostream>
#include<vector>
using namespace std;
//B：二维前缀和也是一样，先拷贝原二维数组，然后进行累加
//   在构建和查询二维前缀和的时候需要用到容斥原理
//   构建公式：sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
//   查询公式(给左上角的(a,b)以及右下角的(c,d))：sum[c][d]=sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1]
//   需要注意的是：处理边界问题，这里习惯地给二维前缀和加上左边界和上边界
//   这时查询公式会相应变化(具体看code)

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+5,vector<int>(m+5)),sum(n+5,vector<int>(m+5));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            sum[i+1][j+1]=a[i][j];//给sum加边界
        }
    }
    //构建：
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
            
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<"\n";
    }
    //查询：
    int t;
    cin>>t;//查询t次
    while(t--){
    int a,b,c,d;//这里的坐标标准是以(1,1)为起点的
    cin>>a>>b>>c>>d;
    cout<<sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1]<<"\n";

    }
    

    

}