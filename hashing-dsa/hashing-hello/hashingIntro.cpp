#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTabe[MAX+1][2];

bool search(int x){
    if(x>=0){
        if(hashTabe[x][0]==1){
            return true;
        }else{
            return false;
        }
    }else{
        x=abs(x);
        if(hashTabe[x][1]==1){
            return true;
        }else{
            return false;
        }
    }
}

void insert(int a[],int n){
    for(int i=0 ;i<n;i++){
        if(a[i]>=0){
            hashTabe[a[i]][0]=1;

        }else{
            hashTabe[abs(a[i])][1]=1;
        }
    }
}

int main(){
    int arr[] ={-1,9,2,-5,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    insert(arr,n);
    int find=-1;
    if(search(find)){
        cout<<"Ele is present"<<endl;
    }else{
        cout<<"ele is not present"<<endl;
    }
}