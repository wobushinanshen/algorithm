#include<bits/stdc++.h>
using namespace std;
//本题涉及：二分答案以及前缀和知识
//哇，感觉得到了升华
//看到区间内还有求和公式，可以想到前缀和(区间求和)

typedef long long ll;
typedef pair<ll,ll> PII;
int n,m;
ll s;
vector<PII>wv(200005);
ll l[200005],r[200005];//在n没有输入，之前不要用(n+5)这样赋值，会出问题，用静态数组算了
ll qzw[200005],qzh[200005];
ll f(int W){
    memset(qzh,0,sizeof(qzh));
    memset(qzw,0,sizeof(qzw));//清空原来的前缀和

    //前缀和考点：
    //这里的前缀和数组(也就是预处理)需要条件判断
    //我们要求的是两个前缀和：
    //1、每个矿石中重量达标(也就是大于等于W的数量)
    //2、每个达标矿石的重量前缀和
    //思考一下怎么构建这个前缀和呢？
    //其实很简单：对于不满足条件的wv[i]，我们让对应的qzh,qzw继承上一个前缀和，也就是当前元素对前缀和没有影响
    //刚开始我是直接没有继承上一个前缀和，后面反应过来这会影响后面的查询操作，因为不满足条件的wv[i]对应
    //的数量前缀和与价值前缀和上面是没有数据的
    for(int i=1;i<=n;i++){
        //如果满足重量大于W，那么就计入前缀和
        if(wv[i].first>=W){
            qzh[i]=qzh[i-1]+1;//数量前缀和
            qzw[i]=qzw[i-1]+wv[i].second;//价值前缀和
        }
        //否则继承上一个值的前缀和
        else{
            qzh[i]=qzh[i-1];
            qzw[i]=qzw[i-1];
        }
    }
    ll y=0;
    for(int i=1;i<=m;i++){
        y+=(qzh[r[i]]-qzh[l[i]-1])*(qzw[r[i]]-qzw[l[i]-1]);
    }
    return y;

}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    ll a=0,b=0;//a b为左右边界
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>wv[i].first>>wv[i].second;//first指w重量，second指v价值
        b=max(b,wv[i].first);//W的最大值就是右边界
    }
    ll ans=1e18;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];

    }
    //二分答案法考点：
    //1、明确题目要求什么，以及需要满足的条件，条件是让y尽量解决s
    //2、谁有范围，很明显就是W，
    //3、W与条件之间的单调性关系？W越大，y会越小，|s-y|会怎样呢，好像不知道
    //但是可以知道如果s>y,说明W太大，需要减小；s<y，说明W要减小
    //所以这里判断W往哪边走的关键是：比较y与s的大小
    while(a<=b){
        ll mid=(a+b)>>1;
        ll current=f(mid);
        ll now_ans=abs(s-current);
        ans=min(ans,now_ans);//记录最小答案
        if(s<=current){//current就是y，s比y小，y大了，说明W要增大来减小y
            a=mid+1;
        }
        else{
            b=mid-1;
        }

    }
    cout<<ans<<"\n";

}