#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int c,m,n;
const int N=300010;
map<int,int>pos;
int l[N];
int r[N];
int e[N];
int main(){
    cin>>c>>m>>n;
    int b[N];
    int index=0,value=0;
    for(int i=1;i<=m;i++){
        
        cin>>index>>value;
        b[index]=value;
        pos[index]=i;
        l[i]=i-1,r[i]=i+1;
    }
    
    for(int i=1,j=1;i<=c;i++){
        
        if(b[i]!=0){
            e[j]=b[i];
            j++;
        }
    }
    int res=m;
    while(n--){
        int x;
        cin>>x;
        int k=pos[x];
        e[k]++;
        while(e[k]>=5){
            res--;
            l[r[k]]=l[k];
            r[l[k]]=r[k];
            int nk=0;
            if(r[k]<=m&&++e[r[k]]>=5)nk=r[k];
            if(l[k]&&++e[l[k]]>=5)nk=l[k];
            k=nk;
        }
        cout<<res<<"\n";
    }
    
}
