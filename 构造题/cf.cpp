#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    a[0]=min(b[0]-a[0],a[0]);
    for(int i=1;i<n;i++){
        ll min_=min(a[i],b[0]-a[i]);
        ll max_=max(a[i],b[0]-a[i]);
        if(max_<a[i-1]){
            cout<<"NO"<<endl;
            return;
        }
        if(min_>=a[i-1]){
            a[i]=min_;
        }
        else{
            a[i]=max_;
        }
    }
    cout<<"YES"<<endl;

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