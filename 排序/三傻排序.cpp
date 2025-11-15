#include<iostream>
using namespace std;
#include<algorithm>
int main(){
    //冒泡排序
    int arr[]={3,8,2,4,5,7,10,9};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
        //比较相邻元素,前者大则交换(升序)
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //选择排序
    int arr2[]={22,15,42,68,33,7,19,90};
    int len2=sizeof(arr2)/sizeof(arr2[0]);
    for(int i=0;i<len2-1;i++){
        int minIndex=i;//假设当前i为最小值下标，j从i+1开始寻找更小值
        for(int j=i+1;j<len2;j++){
            if(arr2[j]<arr2[minIndex]){
                minIndex=j;//如果找到更小元素，更新下标
            }
        }
        swap(arr2[i],arr2[minIndex]);//将找到的最小值与当前i位置元素交换，如果i对应的就是最小值，则交换无影响
    }
    for(int i=0;i<len2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;




    //插入排序
    int arr3[]={29,10,11,23,14,13,18};
    int len3=sizeof(arr3)/sizeof(arr3[0]);
    for(int i=1;i<len3;i++){
        //先是0-1，0-2，0-3，依此类推，就像扑克牌一样，每摸到一张牌，就将它插入到前面已经排好序的牌中，第一张牌默认是排好序的
        //第二张牌插入到前面一张牌中，第三张牌插入到前面两张牌中，依此类推(注意刚开始是没有牌的，是一张一张摸过来，然后插进去排好序)
        //将arr3[i]插入到前面已排好的序列中,规则是：从后往前比较，如果当前arr3[j]小于前一个元素，则交换位置，直到找到合适的位置或者到最左边
        for(int j=i;j>0;j--){//j>0就排除了0-0的情况，因为只有一张牌肯定是排好序的
            if(arr3[j]<arr3[j-1]){
                swap(arr3[j],arr3[j-1]);

            }
        }

    }
    for(int i=0;i<len3;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
}