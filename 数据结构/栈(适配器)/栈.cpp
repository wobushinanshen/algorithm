#include<iostream>
#include<stack>
using namespace std;
//B:今天学习栈
//A：栈？也是数据结构的一种吗，像vector和list
//B：像，但是不是，更准确地说，栈是一个容器适配器
//   学过stl后知道，容器适配器是以一些基础容器为内壳(比如vector)，再包装出来的一个外壳
//   之前的优先队列就是用vector为内壳，然后实现按优先级出队的功能的一个适配器
//   而栈也是如此，内置的栈默认是以deque为内壳的，当然也可以更改内壳容器，不过前提是内壳容器要满足
//   栈所需要的操作
//A：嗯，栈的特点我听过，叫做LIFO，
//B：是的，后面进来的先出去
//   接下来介绍一下常见操作
int main(){
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.empty();//检查是否为空
}