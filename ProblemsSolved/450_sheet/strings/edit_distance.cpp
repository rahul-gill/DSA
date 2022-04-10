#include<cp_debug.h>

/**
 * Given two strings s and t. Return the minimum number of operations required to convert s to t.
 * The possible operations are permitted:
 *  1.Insert a character at any position of the string
 *  2. Remove any character from the string
 *  3.Replace any character from the string with any other character.
 */

int editDistance(string s, string t) {
    int dp[s.size() + 1][t.size() + 1];
    for(int i=0; i<=s.size(); i++){
        for(int j=0; j<=t.size(); j++){
            
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }

    return dp[s.size()][t.size()];
}
