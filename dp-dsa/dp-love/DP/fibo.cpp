#include <bits/stdc++.h> 
using namespace std;


/*

BOTTOM UP(TABULATION)
1) dp[n+1];
2)dp[1]=1;
dp[0]=0;

3) for(int i =2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
return

int main(){
    int n ;
    cin>>n;

    int prev1=1;
    int prev2=0;

    if(n==0) return prev2;

    for(int i=2;i<=n;i++){
        int curr =prev1+prev2;
        //shift logic
        prev2=prev1;
        prev1=curr;
    }

    cout<< prev1<<endl;
    return 0;
}

*/
int fib(int n,vector<int>&dp){
    //base case
    // if(n==1||n==0) return n;
    if(n<=1) return n;

    //step 3
    if(dp[n]!=-1){
        return dp[n];
    }

    //step 2
    // dp[n]=fib(n-1)+fib(n-2);
    dp[n]= fib(n-1,dp)+fib(n-2,dp);

    return dp[n];

}

int main(){
    int n;
    cin>>n;

    //step 1
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }

    cout<<fib(n,dp)<<endl;

    return 0;
}
