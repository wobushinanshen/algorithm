#include<iostream>
using namespace std;
long long arr[1000010];
int dq[1000010];
int dqq[1000010];
long long ans1[1000010];
long long ans2[1000010];
int n,k;
void max_(){
    int h=0,t=0;
    for(int i=0;i<k-1;i++){
        while(h<t&&arr[i]>=arr[dq[t-1]]){
            t--;
        }
        dq[t++]=i;
    }
    int m=n-k+1;
    for(int l=0,r=k-1;l<m;l++,r++){
        while(h<t&&arr[r]>=arr[dq[t-1]]){
            t--;
        }
        dq[t++]=r;
        ans1[l]=arr[dq[h]];
        if(dq[h]==l){
            h++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans1[i]<<" ";
    }
}
void min_(){
    int h=0,t=0;
    for(int i=0;i<k-1;i++){
        while(h<t&&arr[i]<=arr[dq[t-1]]){
            t--;
        }
        dq[t++]=i;
    }
    int m=n-k+1;
    for(int l=0,r=k-1;l<m;l++,r++){
        while(h<t&&arr[r]<=arr[dq[t-1]]){
            t--;
        }
        dq[t++]=r;
        ans1[l]=arr[dq[h]];
        if(dq[h]==l){
            h++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans1[i]<<" ";
    }
}
int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    min_();
    cout<<"\n";
    max_();
    
}