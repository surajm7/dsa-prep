#include <bits/stdc++.h>
using namespace std;

int binarySearch(int s, int e, vector<int> &v, int toFind){
    //Recurion
    if(s>e) return -1;
    // int m=(s+e)>>1;

    int m=(s+e)/2;
    if(v[m]==toFind) 
        return m;
    if(v[m]>toFind) 
        return binarySearch(s,m-1,v,toFind);
    return binarySearch(m+1,e,v,toFind);
       
}

int main() {
    
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    int toFind=4;
    
    cout<<binarySearch(0,v.size()-1,v,toFind)<<endl;
    
    return 0;
}
