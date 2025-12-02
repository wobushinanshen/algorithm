#include<iostream>
#include<algorithm>
using namespace std;
int N;
double L,C,T,VR,VT1,VT2;
const int INF=10000000;
double p[105];
double dp[105];//dp数组的含义是时间，因为最后肯定要比较的是时间
//兔子的时间是固定的，而乌龟的最小时间其实是一个dp来求最优解问题
//步骤：
//明确dp定义：dp[i]表示从起点到第i个站点所需要的最短时间
//状态有哪些：其实只有一个可变参数，就是i(站点变化)，注意电量并不是
//选择：对于当前的dp[i]，其实有i种选择
//分别是：从0(充满电)位置到i,从1(充满电)位置到i，一直到从i-1(充满电)位置到i，
//这里可能要问，为什么每个站点都是充满电状态到i，不是可以选择不充电吗
//那其实是你还没有理解为什么要这样做
//比如从j到i是表示j站点充满电到i，那其实从j-1到i就是在j站点不充电时的时间，
//所以这里要做的事情是，分别求出以0，1，2，3...i-1为最后一个充电的站点到i的时间，再在这些时间中取最小值
//状态转移：dp[i]=min(dp[0]+t2,dp[1]+t2...dp[i-1]+t2)，其中t2表示从j到i的时间，如果j!=0,t2还需要加上充电的时间
//
//初始化：设起点为dp[0],终点是dp[n]

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
            double min_=INF;
            double t2=0;
            //这个内层循环想干嘛？其实这个循环就是i站点的所有选择呀，
            //分别计算从0到i-1站点作为最后一个充电站 到达i站点的时间
            for(int j=0;j<i;j++){
                double betw=p[i]-p[j];
                if(betw<=C){
                    t2=betw/VT1;
                }
                else{
                    t2=(betw-C)/VT2+C/VT1;
                }


                if(j!=0){
                    t2+=T;
                }
                min_=min(min_,dp[j]+t2);



            }
            dp[i]=min_;

            

        }
        double rt=L/VR;
            if(rt>dp[N+1]){
                cout<<"What a pity rabbit!"<<"\n";
            }
            else{
                cout<<"Good job,rabbit!"<<"\n";
            }















    }
}