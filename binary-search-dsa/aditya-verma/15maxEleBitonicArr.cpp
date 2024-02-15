#include <bits/stdc++.h>
 using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int s=0, e=arr.size()-1;
    while(s<e){
       int m = s+(e-s)/2;
        if(m and arr[m] < arr[m-1]) e=m-1;
        else if(m<arr.size()-1 and arr[m] < arr[m+1]) s=m+1;
        else if(m==0){
            if(arr[0]>arr[1]){
                return 0;
            }else return 1;
        }else if(m==e){
            if(arr[e]>arr[e-1]){
                return e;
            }else{
                return e-1;
            }
        }
        else return m;
    } 
    return s;
}
