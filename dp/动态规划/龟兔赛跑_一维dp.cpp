#include<iostream>
#include<algorithm>
using namespace std;
int L,N,C,T,VR,VT1,VT2;
int p[105];
int dp[105];//dp数组的含义是时间，因为最后肯定要比较的是时间
//兔子的时间是固定的，而乌龟的最小时间其实是一个dp来求最优解问题
int main(){
    while(cin>>L){
        cin>>N>>C>>T;
        cin>>VR>>VT1>>VT2;
        p[0]=0;
        p[N+1]=L;
        for(int i=1;i<=N;i++){
            cin>>p[i];
        }
        dp[0]=0;
        for(int i=1;i<=N+1;i++){

            int stop_to_charge=(p[i]-p[i-1])/VT1+(i==1?0:T);
            int not_stop=(p[i]-p[i-1])/VT2;
            dp[i]=min(stop_to_charge,not_stop);

        }















    }
}