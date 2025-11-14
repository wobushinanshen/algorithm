#include<iostream>
#include<queue>
using namespace std;
//谓词 (未完待续……)
struct my_rule{
    bool operator()(int a,int b)const{
        return a>b;
    }
};
int main(){
    priority_queue<int,vector<int>,my_rule>my_queue();//通过写一个谓词来调整优先级规则
    //下面就可以写一些操作了，push() pop() top() empty()这些

}