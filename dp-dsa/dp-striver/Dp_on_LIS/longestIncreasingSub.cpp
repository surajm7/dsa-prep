#include <bits/stdc++.h>
 using namespace std;

int solve(int ind,int prev_ind ,int arr[],int n){
    if(ind==n) return 0;

    int len =0+solve(ind+1,prev_ind,arr,n);
    if(prev_ind==-1||arr[ind]>arr[prev_ind]){
        len=max(len,1+solve(ind+1,ind,arr,n));
    }
    return len;
}


// O(N*N)
//O(N*N)+O(N){AUXILARY SPACE}
int solveMem(int ind,int prev_ind ,int arr[],int n, vector<vector<int>>&dp){
    if(ind==n) return 0;

    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }

    int len =0+solveMem(ind+1,prev_ind,arr,n,dp);
    if(prev_ind==-1||arr[ind]>arr[prev_ind]){
        len=max(len,1+solveMem(ind+1,ind,arr,n,dp));
    }
    return dp[ind][prev_ind+1]= len;
}

int solveSpace(int arr[],int n){
    vector<int>next(n+1,0),curr(n+1,0);

    for(int ind=n-1; ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+next[prev_ind+1];
            if(prev_ind==-1||arr[ind]>arr[prev_ind]){
                len=max(len,1+next[ind+1]);
            }
            curr[prev_ind]=len;
        }
        next=curr;
    }
    return next[-1+1];

}


int longestIncreaSub(int arr[],int n){
    // return solve(0,-1,arr,n);
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return solveMem(0,-1,arr,n,dp);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind=n-1; ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+dp[ind+1][prev_ind+1];
            if(prev_ind==-1||arr[ind]>arr[prev_ind]){
                len=max(len,1+dp[ind+1][ind+1]);
            }
            dp[ind][prev_ind]=len;
        }
    }
    return dp[0][-1+1];
}

int longestIncreaSubTab(int arr[],int n){
    vector<int>dp(n,1);
    int maxi=1;
// sc:O(N)
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i]){
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
  return maxi;
}


//PRINT LIS
int longestIncreaSubTabHash(int arr[],int n){
    vector<int>dp(n,1),hash(n);
    int maxi=1;
    int lastIndex=0;

    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i]&& 1+dp[prev]<dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }

    vector<int>temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    //print the LIS
    reverse(temp.begin(),temp.end());
    for(auto it :temp) cout<< it<<" ";
    cout<<endl;
    return maxi;
}


//....................BIANRY SEARCH................

// TC: O(N*logN)
//SC:O(N)

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           // arr[i] > the last element of temp array 
           
           temp.push_back(arr[i]);
           len++;
        } 
        else{
	// replacement step
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }   
    }
    return len;
}
    



 