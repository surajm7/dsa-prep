#include <bits/stdc++.h>
 using namespace std;

int main(){
    int arr[]={10,20,30,15,10};
    int pref_sum[5];
    for(int i=0;i<5;i++){
        if(i==0){
            pref_sum[i]=arr[i];
        }else{
            pref_sum[i]=pref_sum[i-1]+arr[i];
        }
    }

    for(int i =0;i<5;i++){
        cout<<pref_sum[i]<<" ";
    }cout<<endl;

}