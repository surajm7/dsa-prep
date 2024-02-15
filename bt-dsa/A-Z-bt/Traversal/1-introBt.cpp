//{ Driver Code Starts
// Initial Template for C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countNodes(int i) {
        // your code here
          int ans =1 << (i-1);
          return ans;
        return pow(2,i-1);
        
         //Recursive approach
        //rec case
        if(i==1 || i==2)
        return i;
        
        //base case
        return countNodes(i-1)*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}

// } Driver Code Ends