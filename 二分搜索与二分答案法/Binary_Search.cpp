#include<iostream>
using namespace std;
int main(){
    //有序数组中确定目标值是否存在
    int arr[]={1,3,5,7,9,11,13,15,17,19};
    int n = sizeof(arr)/sizeof(arr[0]);//数组长度
    int target = 13;
    int l=0,r=n-1;
    bool found=false;
    while(l<=r){
        int mid=l+(r-l)/2;//避免溢出的写法
        if(arr[mid]>target){
            r=mid-1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            cout<<"Found at index:"<<mid<<endl;
            break;
            found=true;
        }
    }
    if(found==false){
        cout<<"Not Found"<<endl;
    }


    
    //二分法不仅可以用来查找目标值，还可以用来解决一些变种问题，其本质是利用有序数组的性质，通过不断缩小查找范围来定位目标位置，从而提高效率。

    //二分法的应用:
    //找峰值二分法解决：前提是相邻元素不相等
    int b[]={3,5,4,1,2,6,10,9,8};
    int len=(sizeof(b)/sizeof(b[0]));
    if(len<=1){
        cout<<"peak:"<<b[0]<<endl;
    }
    
    //默认两端为负无穷
    if(b[0]>b[1]){
        cout<<"peak:"<<b[0]<<endl;
    }
    else if(b[n-1]>b[n-2]){
        cout<<"peak:"<<b[n-1]<<endl;

    }
    int l1=1,r1=len-2;
    while(l<=r){
        int mid1=l1+(r1-l1)/2;
        //mid1小于左边，说明左边存在峰值(不排除左右两边都有峰值的可能，此时只找左边即可)
        if(b[mid1]<b[mid1-1]){
            r1=mid1-1;
        }
        //mid1小于右边，说明右边存在峰值
        else if(b[mid1]<b[mid1+1]){
            l1=mid1+1;
        }
        //如果mid1既大于右边又大于左边，则mid1就是峰值
        else{
            cout<<"peak:"<<b[mid1]<<endl;
            break;
        }

    }
}