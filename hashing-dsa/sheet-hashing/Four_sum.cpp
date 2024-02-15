/*
    Problem Link: https://leetcode.com/problems/4sum/
*/

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    // base case: min 4 elements should be there
    if(nums.size() < 4)
        return {};
    // sort the vector
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 3; i++) {
        // avoid duplicates
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        for(int j = i + 1; j < n - 2; j++) {
            // avoid duplicates
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            // now apply pair sum
            int left = j + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    // avoid duplicates
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                }
                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        vector<vector<int>> ans;  
        set<vector<int>> store;   // to store and remove the duplicate answers
		
        for(int i = 0 ; i < n; i++){
		
            for(int j = i + 1; j < n ; j++){
			
               long long  new_target  =  (long long)target - nums[i] - nums[j];
                
                int x = j+1 , y = n-1;
                
                while(x < y){
				
                    int sum = nums[x] + nums[y];
                    
                    if(sum > new_target) y--;
                    else if(sum < new_target ) x++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[x] , nums[y]});
                        x++;
                        y--;
                    };
                }
            }
        }
		
        for(auto i : store){
            ans.push_back(i);  // store the answers in an array(ans)
        }
       return ans;

		//approach no 2
        
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        
        int n = nums.size();
        
        // Approach requires sorting and 2-pointer approach
        
        // Step1 -> sorting
        sort(nums.begin(),nums.end());
        
        
        // Step2 -> 2-pointer 
        for(int i=0; i<n; i++)
        {
            long long int target3 = target - nums[i];
            
            for(int j=i+1; j<n; j++)
            {
                long long int target2 = target3 - nums[j];
                
                int front = j+1;
                int back = n-1;
                
                while(front<back)
                {
                    // remaining elements to be found for quad sum
                    int two_sum = nums[front] + nums[back];
                    
                    if(two_sum < target2)
                        front++;
                    else if(two_sum > target2)
                        back--;
                    
                    else
                    {
                        // if two_sum == target2
                        vector<int> quad(4,0);
                        // quad.push_back(nums[i]);
                        // quad.push_back(nums[j]);
                        // quad.push_back(nums[front]);
                        // quad.push_back(nums[back]);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        
                        
                        res.push_back(quad);
                        
                        // Processing the duplicates of number 3
                        while(front < back && nums[front] == quad[2]) 
                            front++;
                        
                        // Processing the duplicates of number 4
                        while(front < back && nums[back] == quad[3]) 
                            back--;
                    }
                    
                }
                // Processing the duplicates of number 2
                    while(j + 1 < n && nums[j + 1] == nums[j]) 
                        j++;
            }
            // Processing the duplicates of number 2
                    while(i + 1 < n && nums[i + 1] == nums[i]) 
                        i++;
        }
        
        return res;
    }

