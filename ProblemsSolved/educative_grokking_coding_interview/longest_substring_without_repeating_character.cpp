#include<cp_debug.h>

int prevSolution(string s) {
    unordered_set<char> chars;
    int st = 0, end = 0, ans = 0;

    while(end < s.size()){
        if(chars.find(s[end]) == chars.end())
            chars.insert(s[end]);
        else{
            while(s[st] != s[end]){
                chars.erase(s[st]);
                st++;
            }
            st++;
        }
        ans = max(ans, end-st+1);
        end++;
    }
    return ans;
}

/**
 * better
 */

int lengthOfLongestSubstring(string s) {
    vector<int> dict(128, -1);
    //start is exclusive index(not included in the window)
    int maxLen = 0, start = -1;

    for (int end = 0; end != s.length(); end++) {
        //if the character s[end] is already in the window, then shrink the window
        if (dict[s[end]] > start)
            start = dict[s[end]] ;
        //the rightmost index where s[end] character occurs is updated to end
        dict[s[end]] = end;
        maxLen = max(maxLen, end - start );
    }
    return maxLen;
}
int main(){
    cout<<lengthOfLongestSubstring("aabca");
}
