#include <bits/stdc++.h> 
using namespace std;

int main() {
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    int toFind=10,ans=-1;
    
    int s=0,e=v.size()-1;
    while(s<=e){
        int m=(s+e)/2;
    //  m=s+(e-s)/2;
        if(v[m]==toFind){
            ans=m;
            break;
        }
        else if(v[m]>toFind) e=m-1;
        else s=m+1;
    }
    cout<<ans<<endl;
    return 0;
}
