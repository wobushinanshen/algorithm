#include<iostream>
using namespace std;
#include<queue>
//堆结构操作
//这里是用了内置的priority_queue，
//里面已经有push pop top等函数帮我们实现堆的特性了
//但是还是要手搓一下
struct top_min_{
    bool operator()(int a,int b)const{
        return a>b;
    }
};
int main(){
    priority_queue<int,vector<int>,top_min_>min_queue;//定义一个优先队列
    int time;
    cin>>time;
    while(time--){
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            int x;
            cin>>x;
            min_queue.push(x);//push操作后，数组的元素是会修改的
            break;
        
        case 2:
            cout<<min_queue.top()<<"\n";//top操作仅返回顶部元素，不对数组内部进行修改
            break;
        case 3:
            min_queue.pop();
        default:
            break;
        }
    }


}