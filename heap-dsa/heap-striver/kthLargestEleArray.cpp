
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    
      int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
	    for(int i = 1; i < k; i++) pq.pop();
	    return pq.top();
    }
    
    // int findKthLargest(vector<int>& nums, int k) {
    // priority_queue<int,vector<int>,greater<int>> pq;
    //     for(int i=0;i<nums.size();++i){
    //         pq.push(nums[i]);
    //         if(pq.size()>k) pq.pop();
    //     }
    //     return pq.top();            
    // }

//       int partition(vector<int>& arr, int low, int high){
//             int pivot = arr[low];
//             int i = low;
//             for(int j = low+1; j <= high; j++)
//             {
//                 if(arr[j] >= pivot)
//                 {
//                     i++;
//                     swap(arr[i], arr[j]);
//                 }
//             }
//             swap(arr[i], arr[low]);
//             return i;
//     }
    
//     int findKthLargest(vector<int>& nums, int k) {
//             int low = 0, high = nums.size() - 1, index;
//             while(low <= high)
//             {
//                 index = partition(nums, low, high);
//                 if(k == index+1)
//                     break;
//                 else if(k < index+1)
//                     high = index - 1;
//                 else
//                     low = index + 1;
//             }
//             return nums[index];
//     }
};
    