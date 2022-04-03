#include<bits/stdc++.h>
using namespace std;

/**T
 * here is an integer array nums sorted in ascending order (with distinct values).
 * Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 * You must write an algorithm with O(log n) runtime complexity.
 */


int search(vector<int>& nums, int target) {
    int n = nums.size(), lo = 0, hi = n-1;
 
    /* If arr[l...mid] is sorted 
     * then we can check easily if key is in arr[l...mid]
     * - if it is in arr[l...mid] we binary search for it in that range
     * - else we perform this algorithm on arr[mid...end]
     */
    while(lo<=hi){
        int m = (hi+lo)/2;
        if(nums[m] == target)
            return m;
        else if(nums[m] >= nums[lo]){
            if(target>=nums[lo] and target<=nums[m])
                hi = m-1;
            else
                lo = m+1;
        }
        else{
            if(target >= nums[m] and target <= nums[hi])
                lo = m+1;
            else
                hi = m-1;
            
        }
    }
    
    return -1;
}


int main(){
    vector<int> arr{4,5,6,7,0,1,2};
    cout<<search(arr, 0);
}
