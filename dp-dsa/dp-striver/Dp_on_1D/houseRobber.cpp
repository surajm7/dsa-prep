#include <bits/stdc++.h>
 using namespace std;


int maximumNonAdjSumTab(vector<int>&nums){
    int n =nums.size();
    int prev =nums[0];
    int prev2=0;
    
    for(int i =1;i<n;i++){
        int take =nums[i];
        if(i>1) take+=prev2;
        int notTake=0+prev;

        int curr_i =max(take, notTake);
        prev2=prev;
        prev=curr_i;
    }
    return prev;
}



long long int houseRobber(vector<int>& valueInHouse){
    vector<int> temp1,temp2;
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjSumTab(temp1),maximumNonAdjSumTab(temp2));
}