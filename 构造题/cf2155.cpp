#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k;
    cin>>n>>k;
    if(k==n*n-1){
        cout<<"NO"<<endl;
        return;
    }
    char a[105][105];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]='H';

        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cnt==k)break;//这行必须写在前面，不然k==0的时候，a[0][0]还是赋值了'U'，就因为这个WA的
            a[i][j]='U';
            cnt++;
            

        }
        if(cnt==k)break;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='H'){
                if(i!=n-1){
                    a[i][j]='D';
                }
                else{
                    if(i==n-1&&j==n-1){
                        a[i][j]='L';
                    }
                    else{
                        a[i][j]='R';
                    }
                }
            }
        }
    }
    cout<<"YES"<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<a[i][j];

        }
        cout<<"\n";
    }
    





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