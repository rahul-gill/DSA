#include<cp_debug.h>

int totalFruit(vector<int>& fruits) {
    int st = 0, end = 0, ans = 0;
    unordered_map<int,int> mp;
    while(end < fruits.size()){
        mp[fruits[end]]++;
        
        while(mp.size() > 2){
            mp[fruits[st]]--;
            if(mp[fruits[st]] == 0)
                mp.erase(fruits[st]);
            st++;
        }
        
        ans = max(ans, end-st+1);
        end++;
    }
    return ans;
}
