#include<iostream>
using namespace std;
//这题是有初始值的差分操作
int a[5000005]={0};
int diff[5000005]={0};
int main(){
    int n,p;
    cin>>n>>p;
    
    //对于有初始值的数组，先构建一个差分数组，或者像下面这样单独给每个初始值都做一次差分
    // int pre=0;
    // int temp=0;
    // for(int i=1;i<=n;i++){
    //     cin>>temp;
    //     a[i]=temp;
    //     a[i]-=pre;
    //     pre=temp;

    // }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        diff[i]=a[i]-a[i-1];
    }//a数组是原数组，diff数组是差分数组

    
    int l,r,num;//从l到r，加上num

    while(p--){
        cin>>l>>r>>num;
        diff[l]+=num;
        diff[r+1]-=num;//这里就展现出差分修改数据的优势，只需要在l和r+1位置分别+num和-num，差分数组就算
        //              修改完成了
        
    }
    
    for(int i=1;i<=n;i++){
        
        diff[i]+=diff[i-1];//其实这里应该写成a[i]=a[i-1]+diff[i],这样更符合差分定义
    }
    int min_=101;
    for(int i=1;i<=n;i++){
        min_=min(min_,diff[i]);
    }
    
    cout<<min_;
}