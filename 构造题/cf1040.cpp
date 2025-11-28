#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>target){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(sum==target){
        cout<<-1<<"\n";
        return;
    }
    int b=target-sum;
    if(b!=1){
        cout<<-1<<"\n";
        return;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cout<<a[i]<<" ";
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==2){
            cout<<a[i]<<" ";
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cout<<a[i]<<" ";
        }
    }
    cout<<"\n";


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;//只要求一组数据时，把此行注释掉。
    while (T--) {
        solve();
    }
    return 0;
}