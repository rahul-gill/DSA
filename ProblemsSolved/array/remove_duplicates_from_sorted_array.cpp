#include<cp_debug.h>


int removeDuplicates(vector<int>& nums) {
    return unique(nums.begin(), nums.end()) - nums.begin();
}

int removeDuplicates(vector<int>& nums) {
    int unique = 1;
    
    for(int i=1; i<nums.size(); i++)
        if(nums[i] != nums[i-1])
            nums[unique++] = nums[i];
    
    return unique;
}
