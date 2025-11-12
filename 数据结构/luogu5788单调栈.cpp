#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//A：单调栈，是啥？跟栈有什么区别吗
//B：单调栈，顾名思义，就是确保栈内元素保持单调的一个栈(如果栈存的是下标，那么就是下表对应的数保持单调)
//   单调栈的实现=栈的操作+手写控制行为
//   废话不多说，直接实现--洛谷5788
long long arr[3000010];
int ans[3000010];

int main(){
    stack<int> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    //输入数组，没啥好说
    s.push(1);//先给s push第一个数
    for(int i=2;i<=n;i++){//从2开始
        //注意，栈存的是下标
        while(!s.empty()&&arr[s.top()] <arr[i]){
            ans[s.top()]=i;
            s.pop();

        }
        //s不空并且新元素的加入会破坏原有栈内元素的单调性时，弹出队列元素
        //直至新元素插入不影响单调性，或者栈为空
        s.push(i);
        //等到弹出操作结束后，再将新元素加入栈

    }
    //最后栈内会剩下一些没弹出的元素，这说明他们后面都没有比他们大的元素了，不然他们早就弹出了
    //所以都赋值为0
    while(!s.empty()){
        ans[s.top()]=0;
        s.pop();//记录一个，就弹出一个
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

}