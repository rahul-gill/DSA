#include<cp_debug.h>

/**
 * Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, 
 * and all the 0's and all the 1's in these substrings are grouped consecutively.
 * Substrings that occur multiple times are counted the number of times they occur.
 */

int countBinarySubstrings(string s) {
    int lastCount = 0, currCount = 1, curr = s[0];
    int ans = 0;

    for(int i=1; i<s.size(); i++){
        if(lastCount > 0 && curr == s[i]){
            ++ans;
            --lastCount;
        }

        if(curr == s[i])
            ++currCount;
        else {
            lastCount = currCount-1;
            currCount = 1;
            curr = s[i];
            ++ans;
        }
    }    
    return ans;
}


