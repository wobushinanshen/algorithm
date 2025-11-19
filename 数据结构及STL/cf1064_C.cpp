#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
//本题是用到的数据结构以及对应功能：
//1、双向链表：用于合并元素后快速删除
//2、pair对组，用于同时存元素值和元素下标，用于待会的映射：选定一个元素值，我要知道他的下标
//3、优先队列(小根堆)，有重复元素，map不合适了，而且优先队列的堆顶就是我要的最小值，更符合本题意图


using namespace std;
typedef pair<int,int>PII;//要通过值来得到索引，对组是不二之选
//因为优先队列默认根据对组的first值进行排序，就不用定义排序方式了(如果选择构建结构体的话，就要写个cmp函数规定按谁排序)
PII a;
int e[200005];
int l[200005],r[200005];
void solve(){
    
    //我需要一个数据结构，可以帮我随时跟踪最小元素的索引
    //因为可能会有多个最小值，因此不选择map
    //这时我想到了优先队列，虽然优先队列对相同元素的排序未定义
    //但是对于这道题，只要我们可以在每一步得到一个最小值索引，并且每一步处理的都是最小值即可
    priority_queue<PII,vector<PII>,greater<PII> >b;//定义小根堆，从小到大
    int n;
    cin>>n;
    int max_=0;
    for(int i=1;i<=n;i++){
        
        cin>>e[i];
        max_=max(max_,e[i]);
        l[i]= i==1?n:i-1;
        r[i]= i==n?1:i+1;
        b.emplace(e[i],i);//emplace默认是根据pair的first值进行排序，因此对组就很方便
    }
    //这样小根堆每个元素first就是值的大小，同时堆顶的值是最小的，因此要找最小值的索引就是堆顶对组的second值
    long long res=0;
    n--;//进行n-1次操作
    while(n--){
        if(n==1){
            res+=max_;
        }
        else{
        int min_=b.top().second;//取最小值索引,待会还要删除这个索引
        b.pop();//取完后弹出
        int min_pos=e[l[min_]]<=e[r[min_]]?l[min_]:r[min_];//选择最小相邻索引
        res+=e[min_pos];//加上最小相邻值
        l[r[min_]]=l[min_];
        r[l[min_]]=r[min_];
        }
    }
    cout<<res<<"\n";
    


    
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}