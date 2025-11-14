#include<iostream>
using namespace std;
#include<queue>
//A：队列的特点就是先进先出吧。
//B：没错，这就是First In, First Out
//A：那我有什么办法去实现队列，或者说证明我写的东西就是一个队列。
//B：证明你写的东西是一个队列，其实本质上就是要实现队列的几个特性：
//   分别是：放元素，取元素。
//   下面介绍几种方法实现队列。


int main(){
    //第一种：使用内置的适配器queue，其内壳容器是deque，可以自定义实现容器，但是容器要支持一定的功能
    //比如vector就不行，因为它不支持front()功能
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);//入队
    cout<<q1.front()<<endl;//返回队首元素
    q1.pop();//弹出队首元素
    cout<<q1.front()<<endl;
    //第二种：使用数组来模拟

}