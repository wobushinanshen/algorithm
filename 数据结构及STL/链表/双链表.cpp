#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.remove(2);
    for(auto a=l.begin();a!=l.end();a++){
        cout<<*a<<" ";
    }
    cout<<"\n";
    cout<<l.back()<<"\n";
    if(l.empty()){
        cout<<"List is empty"<<endl;
    }
    else{
        cout<<"List is not empty"<<endl;
    }
    l.pop_back();
    l.pop_front();
    for(auto b=l.begin();b!=l.end();b++){
        cout<<*b<<" ";
    }
    cout<<"\n";
    l.erase(l.begin());
    
}
  