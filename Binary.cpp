#include<iostream>
using namespace std;
//打印整数的二进制表示
void printBinary(int n){
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;//取出第i位，与1按位与得到该位的值，即为第i位的二进制值(利用了按位与的性质，只有两个位都为1时结果才为1)
        
        cout<<bit;

        if(i%8==0) cout<<" ";//每8位加一个空格，便于阅读
    }
    cout<<endl;
}
int main(){
    //二进制位运算
    //按位与&：都为1，结果才为1
    int a=5,b=3;
    cout<<"a,b:"<<endl;
    printBinary(a);
    printBinary(b);
    cout<<"a&b:"<<endl;
    printBinary(a&b);

    //按位取反~：0变1，1变0
    cout<<"~a"<<endl;
    printBinary(~a);

    //按位或|:
    cout<<"a|b:"<<endl;
    printBinary(a|b);

    //按位异或^：不同才为1
    cout<<"a^b:"<<endl;
    printBinary(a^b);

    //负数的表示：取反加一
    cout<<"-a:"<<endl;
    printBinary(~a+1);
    //左右移位操作：<<  >>
    cout<<"a<<1:"<<endl;
    printBinary(a<<1);//左移一位，相当于乘以2
    cout<<"a>>1:"<<endl;
    printBinary(a>>1);//右移一位，相当于除以2
    //



   //0x表示十六进制
    printBinary(a);
    cout<<a<<endl;//输出十进制
    int aa=(~a)+1;//取反加一，得到负数的补码表示：也就是取负数
    printBinary(aa);
    cout<<aa<<endl;//输出负数
    cout<<"-----------------"<<endl;//0b表示二进制
    printBinary(b);
    cout<<b<<endl;//输出十进制
    int bb=(~b)+1;//取反加一，得到负数的补码表示：也就是取负数
    printBinary(bb);
    cout<<bb<<endl;//输出负数
}
