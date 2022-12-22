#include<cp_debug.h>

int characterReplacement(string s, int k) {
    int st = 0, end = 0, ans = 0;
    int max_char_freq = 0;
    unordered_map<char, int> mp;

    while(end < s.size()){
        mp[s[end]]++;
        max_char_freq = max(max_char_freq, mp[s[end]]);
        
        while(end-st+1 - max_char_freq > k){
            mp[s[st]]--;
            if(mp[s[st]] == 0)
                mp.erase(s[st]);
            st++;
        }
        ans = max(ans, end-st+1);
        end++;
    }
    return ans;
}
