#include<cp_debug.h>


/**
 * Given a string S, find the longest palindromic substring in S.
 * Incase of conflict, return the substring which occurs first ( with the least starting index).
 */


string longestPalindrome(string s) {
    if (s.size() == 1 )
        return s;

    int size = s.size(), start = 0, len = 1;

    for (int i=0; i< size;){
        
        if(size-i<=len/2)
            break;
        
        int j = i, k = i;
        
        //to take into account  the even length palindromes
        while(k<size-1 && s[k+1]==s[k])
            ++k;
        
        i = k+1;
        while(k<size-1 && j>0 && s[j-1]==s[k+1])
            ++k, --j;
        
        int new_len = k - j +1; 
        if(new_len>len){
            start = j;
            len = new_len;
        }
    
    }
    return s.substr(start,len);
}

int main(){
    cout<<longestPalin("cbbd");
}
