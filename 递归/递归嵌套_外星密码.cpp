#include <bits/stdc++.h>
using namespace std;
//A：哎，递归好难
//B：明白一个函数的作用并相信它能完成这个任务
//   千万不要跳进这个函数里面企图探究更多细节， 否则就会陷入无穷的细节无法自拔，人脑能压几个栈啊
//A：呜，错了，再也不去深入了
//B：多刷题，感觉上来了就好了。

//下面是一道解码题：输入ej3[kr2[fe]]
//输出：ejkrfefekrfefekrfefe

//g函数负责解一个嵌套，比如将3[fn]解为fnfnfn并返回该结果
string g(int num, string s_) {
    string res;
    for (int i = 0; i < num; i++) {
        res += s_;
    }
    return res;
}
int where=0;
//
string f(string s, int i) {
    string path;
    int cnt = 0;
    while(i<s.size()&&s[i]!=']'){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            path.push_back(s[i++]);
        }
        else if(s[i]>='0'&&s[i]<='9'){
            cnt=cnt*10+s[i++]-'0';
        }
        else{
            path.append(g(cnt,f(s,i+1)));
            i = where +1;
            cnt=0;
        }
    }
    where =i;
    return path;
}

void solve() {
    string s;
    cin >> s;
    int index = 0;
    cout << f(s, index) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T = 1;
    // cin >> T; // 只要求一组数据时，把此行注释掉
    while (T--) {
        solve();
    }
    return 0;
}