#include<cp_debug.h>

int wordBreak(string s,vector<string> dictx){
    unordered_set<string> dict(dictx.begin(), dictx.end());

    int n = s.size();
    //dp[i] true if s[0:i] can be built using the dictionary
    vector<bool> dp(n+1);
    dp[0] = 1;
    //for earch length len possible of substrings of s, check:
    //if s[0:i] is true(can be build using dictionary) and s[i+1:len] is in dictionary
    //if for any i its true then dp[len] is also true
    for(int len = 1;len<=n;len++)
        for(int i = 0;i<len;i++)
            if(dp[i] && dict.find(s.substr(i,len- i)) != dict.end()){
                dp[len] = 1;
                break;
            }

    return dp[n];
}
