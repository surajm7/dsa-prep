#include <bits/stdc++.h>
using namespace std;

int numOfElInter(int a[],int b[] ,int n ,int m){   
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }

    int count=0;
    for(int i =0;i<m;i++){
        int key =b[i];
        if(s.find(key)!=s.end()){
            count++;
            s.erase(key);
        }
    }
    return count;
}