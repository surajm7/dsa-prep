#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);

    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
   
    cout<<"numberof element: "<< s.size()<<"\n";

    // s.clear();
    // cout<<"number of element : "<<s.size()<<endl;

    int key=25;

    if(s.find(key)==s.end()){
        cout<<"key not found"<<endl;
    }else{
        cout<<"key found"<<endl;
    }

    int deleted_key=15;
    s.erase(deleted_key);

    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    cout<<"numberof element: "<< s.size()<<"\n";

    if(s.find(key)!=s.end()){
        cout<<"ke found"<<endl;
    }

    if(s.count(5)){
        cout<<"key found"<<endl;
    }else{
        cout<<"key not found"<<endl; 
    }
}