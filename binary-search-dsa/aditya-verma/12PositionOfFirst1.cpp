#include <bits/stdc++.h>
 using namespace std;

int firstIndex(int a[], int n) {        
    int i=0,j=n-1;
    while(i<j){
        int m = i+(j-i)/2;
        if(a[m]) j=m;
        else i=m+1;
    }
    if(!a[i]) return -1;
    return i;
}
