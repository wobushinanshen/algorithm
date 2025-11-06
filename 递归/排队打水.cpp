#include<iostream>
using namespace std;
#include<algorithm>
#include<iomanip>
struct person{
    int num;
    int time;
};
bool cmp(person a,person b){
    return a.time<b.time;

}
int main(){
    int n;
    cin>>n;
    person a[1010];
    for(int i=0;i<n;i++){
        cin>>a[i].time;
        a[i].num=i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].num<<" ";
    }
    cout<<endl;
    double sum=0;
    for(int i=1;i<n;i++){
        sum+=a[i-1].time*(n-i);
    }
    double nn=n;
    cout<<fixed<<setprecision(2)<<sum/nn;
}