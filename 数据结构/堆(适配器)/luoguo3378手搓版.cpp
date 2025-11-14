#include<iostream>
#include<algorithm>
using namespace std;
//数组模拟堆操作：虽然堆的结构只存在于想象中，但是
//通过数组中下标的联系，我们确确实实是在对一个堆进行操作

int arr[1000010];
int size,i=0; //这个i的作用就是全程跟踪要插入的元素，以及删除元素后被交换到顶部的元素。(所以i有两个用处)
//手搓版堆结构：以最小值为例

//对插入的元素进行向上调整
//向上调整
//push进来一个元素
//首先用i记录其在数组中的下标(这个在主函数中实现),传入i
//不断将i与(i-1)/2(也就是与其父级上的元素进行比较)
void push(int arr[],int i){
    //直到该元素比父亲大，或者已经到0位置
    while(arr[i]<arr[(i-1)/2]){ //当i等于0时(i-1)/2也是0喔，所以这个循环条件同时也可以判断是否到了0位置
        swap(arr[i],arr[(i-1)/2]);//交换父子元素
        i=(i-1)/2;//更新该元素的位置(维持状态)

    }
    
    
}
//向下调整
//当删除最小元素时，堆结构会散掉，因此要修改堆结构
//常见做法就是将数组最后一个元素与0位置元素交换，然后size--(这里就相当于把原来的顶部元素去掉了)
//然后对现在的顶部元素(也就是原来的尾部元素)进行向下调整。
//这样就又可以维持堆结构了
//需要注意代码细节
void pop(int arr[]){
    i=0;//让i=0，因为交换后我要跟踪的是顶部的元素吧。
    swap(arr[size-1],arr[0]);//先交换0位置与末位置
    size--;//--去掉原来0位置的数
    int son=2*i+1;//根据i计算左子节点的位置(加下来原理跟push差不多了，都是比较)
    while(son<size){
        int best=son+1<size&&arr[son+1]<arr[son] ? son+1 : son;//son+1表示右子节点，这个语句是先判断左右子节点的大小，然后返回比较小的那个
                                                              //作为best的值
        best = arr[i]<arr[best]?i:best;//再将被跟踪元素和best对应的值比较，选出这个子树的最小值对应的下标，并赋给best
        if(best==i){//如果best就是i，说明i位置上的数就是最小的，目标完成，break
            break;
        }
        swap(arr[best],arr[i]);//如果if语句没进去的话，就交换best和i下标的值
        i = best;//更新i
        son=i*2+1;//再更新son
    }
}
//返回最小元素
void top(){
    cout<<arr[0]<<"\n";
}
int main(){
   
    int t;
    cin>>t;
    while(t--){
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            int x;
            cin>>x;
            arr[size]=x;
            i=size;//因为我的i有两个用途，所以每个函数前都要重新给i赋值，实现push操作前，i的值就是元素个数，因为size就等于数组中新增元素的下标
            //就比如size等于1时，数组只有一个元素，即arr[0],当加入新元素时，你要用i跟踪这个新元素，那么i是不是就是1，arr[1]嘛，
            size++;//然后更新size值
            push(arr,i);
            break;
        case 2:
            top();
            break;
        case 3:
            pop(arr);
            break;
            
        default:
            break;
        }
    }
   
}