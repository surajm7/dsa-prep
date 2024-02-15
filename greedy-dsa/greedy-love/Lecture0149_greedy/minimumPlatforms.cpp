#include <bits/stdc++.h> 
using namespace std;


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    // Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);

        //maintain max yrain at a perticular time
        // int N =arr.size();
        int i=0; //pointing to arrival time
        int j=0;//pointing to departure time

        int maxTrain=0;
        int platform=0;

        while(i<n&& j<n){
            if(arr[i]<=dep[j]){
                maxTrain++;
                i++;
            }else{
                maxTrain--;
                j++;
            }
            platform=max(platform,maxTrain);
        }
        return platform;
    }
};