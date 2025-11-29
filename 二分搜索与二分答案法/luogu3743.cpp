#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double n,p,sum;//sum是所有设备消耗电的总速率
double v[100005],en[100005];
#define eps 0.000001

//对于每个固定的时间，判断是否满足条件
//什么条件？就是该时间内，所有设备都不会断电
//怎么判断是否满足？
//算出time时间内，所有设备所需求的总电量total(注意，total不是sum*time这么简单)
//让total和time*p比较
//关键是total怎么算：它是在time这个答案下的需求，也就是说
//如果time时间内，某个设备是不用充电也可以不断电，那么就不用考虑这个设备了
bool f(double time){
    double total=0;
    double total_=time*p;
    for(int i=1;i<=n;i++){
        if(v[i]*time>en[i]){
            total+=(v[i]*time-en[i]);
        }
    }
    return total<=total_?true:false;

}
int main(){
    cin>>n>>p;
    
    for(int i=1;i<=n;i++){
        cin>>v[i]>>en[i];
        sum+=v[i];//统计总速率和
    }
    //如果总速率和小于p，说明所有设备可以永远不断电
    if(sum<=p){
        cout<<-1<<endl;
        return 0;
    }
    double l=0,r=1e10,ans;

    while(r-l>=eps){
        double mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}