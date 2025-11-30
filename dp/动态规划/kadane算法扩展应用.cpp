#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//本题是codeforces1067(div.2)的C题
//博弈部分的大意就是：Alice先手，k是奇数的时候Alice是最后一个操作的，k是偶数的时候，Bob是最后一个操作的，
//而两人的最优选择都是抵消对方的选择，所以最后一步决定最大子区间和
//偶数：完全抵消，最大子区间和就是a[i]的最大子区间和
//奇数：Alice可以操作最后一次，暴力的话，遍历a[i]，每个a[i]+b[i]，(每个i求完要a[i]-b[i]),再用kadane算法求
//时间复杂度是O(n^2),嵌套循环了
//可以用前缀与后缀搭配来优化，这里的前缀就是指以i为结尾的最大子区间和，后缀指以i为开头最大子区间和
//然后遍历一次a[i],对每个位置上的a[i],它左边最大子区间是max(dp[i-1],0)
//右边最大子区间是max(dp[i+1],0)
//记录current=a[i]+b[i]+left+right,再用ans=max(ans,current)记录最大的那个区间
void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll>a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<ll>dp(n+2),dp1(n+2);
    if(k%2==0){
        //kadane算法算以i结尾的最大子区间和
        ll ans=a[1];
        dp[1]=a[1];//dp[1]=a[1]，下面dp从2开始
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
            ans=max(dp[i],ans);//记录下以i结尾的最大区间和中最大的区间和
        }
        cout<<ans<<endl;
    }
    else{
        ll ans=a[1];
        //以i结尾的最大子区间和
        dp[1]=a[1];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
        }
        //以i开头的最大子区间和
        dp1[n]=a[n];
        for(int i=n-1;i>=1;i--){
            dp1[i]=max(a[i]+dp1[i+1],a[i]);
        }
        //左+右+a[i]+b[i]
        for(int i=1;i<=n;i++){
            ll left_max=max(0ll,dp[i-1]);//0ll指long long类型的0
            ll right_max=max(0ll,dp1[i+1]);//左右的最大子区间和0比较，因为小于0的肯定不要呀
            ll temp=left_max+right_max+a[i]+b[i];
            ans=max(ans,temp);

        }

        cout<<ans<<endl;





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