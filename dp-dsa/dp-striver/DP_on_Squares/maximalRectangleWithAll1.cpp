#include <bits/stdc++.h>
 using namespace std;

class Solution{
    public:
    vector<int>nextSmaller(vector<int>arr){
        stack<int>s;
        s.push(-1);

        int n =arr.size();
        vector<int> ans(n);
        for(int i =n-1;i>=0;i--){
            int item=arr[i];

            while(s.top()!=-1&&arr[s.top()]>=item){
                s.pop();
            }

            //push in ans
            if(s.top()==-1){
                ans[i]=n;
            }else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int>prevSmaller(vector<int>arr){
        stack<int>s;
        s.push(-1);

        int n =arr.size();
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            int item=arr[i];

            while(s.top()!=-1&&arr[s.top()]>=item){
                s.pop();
            }

            //push in ans
           ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    int largestArea(vector<int>arr){
        vector<int>prev=prevSmaller(arr);
        vector<int>next=nextSmaller(arr);

        int maxArea =INT_MIN;

        for(int i =0;i<arr.size();i++){
            int length =arr[i];
            int breadth=next[i]-prev[i]-1;
            int newArea=length*breadth;
            maxArea=max(maxArea,newArea);
        }
        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>&matrix){
        int maxi =INT_MIN;

        vector<int> histogram(matrix[0].size(),0);

        for(int i =0;i<matrix.size();i++){
            //to create histogram array
            for(int j =0;j<histogram.size();j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }else{
                    histogram[j]=0;
                }
            }
        maxi=max(maxi,largestArea(histogram));
        }
        return maxi;
    }

};

class Solution {
public:
    int maxarea(vector<int> &v){
        stack<int> s;
        int ans=0;
        for(int i=0; i<=v.size(); i++){
            while(!s.empty() && (i==v.size() || v[s.top()]>v[i])){
                int cur=s.top();
                s.pop();
                int width = s.empty()? i:i-s.top()-1;
                ans = max(ans, width*v[cur]);
            }
            s.push(i);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> curr(n, 0);
        
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')     curr[j]++;
                else    curr[j]=0;
            }
            int area = maxarea(curr);
            ans=max(ans, area);
        }
        
        return ans;
    }
};