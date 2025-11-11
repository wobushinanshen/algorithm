#include<iostream>
using namespace std;
int arr[1000000];

//B:这题其实是实现一个队列，使用数组来模拟（当然也可以用其他数据结构）
//A：数组模拟队列？
//B：其实模拟的是队列的逻辑结构罢了，然后还有模拟队列对应的操作，比如弹出首元素，加入元素，返回首元素
//   方法很简单，只需要借助两个索引l和r
int main(){
    int t;
    cin>>t;
    int l=0,r=0;
    while(t--){
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            int x;
            cin>>x;
            arr[r]=x;
            r++;
            break;

        case 2:
            if(arr[l]==0){
                cout<<"ERR_CANNOT_POP"<<"\n";
            }
            else{
                arr[l]=0;
                l++;
            }
            break;

        case 3:
            if(arr[l]==0){
                cout<<"ERR_CANNOT_QUERY"<<"\n";

            }
            else{
                cout<<arr[l]<<"\n";
            }
            break;
        case 4:
            cout<<r-l<<"\n";
            break;
        default:
            break;
        }
    }
}