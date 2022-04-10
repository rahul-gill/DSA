#include<bits/stdc++.h>
using namespace std;

/**
 * We have to check if string s can be gotten by using characters of s1 and s2
 * for example 
 * 1XY2 is a valid shuffle of XY and 12
 * Y1X2 is a valid shuffle of XY and 12
 * Y21XX is not a valid shuffle of XY and 12
 */

boolean shuffleCheck(string &s, string &s1, string &s2){
    if(s1.size() + s2.size() != s.size()) 
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s.begin(), s.end());

    int i=0, j=0, k=0;

    while(k < s.size()){
        if(i < s1.size() && s1[i] == s[k])
            i++;
        else if(j < s2.size() && s2[j] == s[k])
            j++;
        else 
            return false;
        
        k++;
    }

    return !(i < s1.size() || j < s2.size());
}

