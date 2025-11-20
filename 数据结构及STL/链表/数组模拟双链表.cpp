#include<iostream>
using namespace std;
//三个数组模拟双链表，可快速删除元素，插入元素，适用于需要频繁插入删除操作的题目
//下面介绍创建，赋值，以及删除
int main(){
    int e[100],l[100],r[100];
    int n=10;//n最大为98，因为要给l，r各自留一个边界位置
    for(int i=1;i<=n;i++){
        cin>>e[i];
        l[i]=i-1;
        r[i]=i+1;

    }
    


}