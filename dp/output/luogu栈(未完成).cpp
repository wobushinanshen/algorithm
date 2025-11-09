#include<iostream>
using namespace std;
int k=0;
int n;
int a[40][20];
int way(int k,int many)
{
    int t=0;//计数
    if(k==2*n)//如果步数已满，返回
    {
        if(many==0)//所有操作完成后栈是否清空
            return 1;
        else
            return 0;
    }
    if(a[k][many]!=0)//此处为了加速用了一个记忆化
        return a[k][many];
    if(many<=n)//栈不是满的就可以push
        t+=way(k+1,many+1);
    if(many>0)//栈不是空的就可以pop
        t+=way(k+1,many-1);
    a[k][many]=t;
    return t;
}
int main(){
    cin>>n;
    cout<<way(k,n);
}
