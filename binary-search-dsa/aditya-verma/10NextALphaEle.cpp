#include <bits/stdc++.h>
 using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
        
    int s=0,e=letters.size()-1,ans=0;

    while(s<=e){
        int m = s+(e-s)/2;
        if(letters[m]<=target) s=m+1;
        else{
            if(ans==0 or letters[m]<letters[ans]) ans=m;
            e=m-1;
        }
    }

    return letters[ans];
}
