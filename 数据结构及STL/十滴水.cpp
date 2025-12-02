#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
//十滴水正解
//这题涉及数组模拟双链表，以及哈希表的使用
//利用了双向链表删除只需O(1)和哈希表查找只需O(1)的特性

//1、双向链表，可快速删除已经爆开的水滴(爆开的水滴变为0，不会再有任何影响)
//2、map哈希表：因为题目会输入一个索引来加入水滴，而我们的链表只存了不为0的元素
//   因此我们需要将题目输入的索引对上链表的索引
int c,m,n;
const int N=300010;
unordered_map<int,int>pos;
typedef pair<int,int>PII;
PII q[N];
int l[N];//
int r[N];//
int e[N];//链表
int main(){
    cin>>c>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>q[i].first>>q[i].second;
    }
    sort(q+1,q+m+1);//默认按first值排序
    for(int i=1;i<=m;i++){
        l[i]=i-1,r[i]=i+1;
        e[i]=q[i].second;
        pos[q[i].first]=i;
    }
    int res=m;
    while(n--){
        int x;
        cin>>x;
        int k=pos[x];
        e[k]++;
        while(e[k]>=5){
            res--;
            l[r[k]]=l[k];
            r[l[k]]=r[k];
            int nk=0;
            if(r[k]<=m&&++e[r[k]]>=5)nk=r[k];
            if(l[k]&&++e[l[k]]>=5)nk=l[k];
            k=nk;
        }
        cout<<res<<"\n";
    }
    
    
}
