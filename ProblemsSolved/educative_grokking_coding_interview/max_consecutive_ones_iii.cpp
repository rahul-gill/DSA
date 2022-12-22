#include<cp_debug.h>

int longestOnes(vector<int>& nums, int k) {
    int st = 0, end = 0, ans = 0, zeros = 0;


    while(end < nums.size()){
        if(nums[end] == 0)
            zeros++;
            
        while(zeros > k){
            if(nums[st] == 0)
                zeros--;
            st++;
        }
        ans = max(ans, end-st+1);
        end++;
    }
    return ans;
}
