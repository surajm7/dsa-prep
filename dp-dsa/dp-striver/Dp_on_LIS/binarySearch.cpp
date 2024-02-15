#include <bits/stdc++.h> 
using namespace std;


int main(){
    int arr[] ={1,4,5,8,9};
    int n=arr.size();

// bool res =bianry_search(a,a+n,3);
// bool res =bianry_search(a,a+n,4);

// lower_bound function:
int ind =lower_bound(a,a+n,4)-a;
int ind =lower_bound(a,a+n,7)-a;
int ind =lower_bound(a,a+n,10)-a;

int a[] ={1,4,5,8,9,9};

// upper_bound function:
int ind =upper_bound(a,a+n,4)-a;
int ind =upper_bound(a,a+n,7)-a;
int ind =upper_bound(a,a+n,10)-a;


}
