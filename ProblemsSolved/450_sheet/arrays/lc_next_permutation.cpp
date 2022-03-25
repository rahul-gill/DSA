#include<bits/stdc++.h>
using namespace std;

/**
 * - for descending order permutation, no next larger permutation is possible.
 * - So we need to find first pair of elements from the right {a[i], a[i-1]}, which satisfy a[i−1] < a[i]
 * - Now to find next permutation, we'll have to rearrange the sub array a[0 : i-1]'s elements
 * - We need to replace the number a[i−1] with the number which is just larger than itself among the numbers lying to its right section
 * - then we'll reverse the sub array on right of a[i-1]
 * https://leetcode.com/media/original_images/31_Next_Permutation.gif
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 && nums[i]<=nums[i-1])
            --i;

        if(i>0) {
            int j = nums.size() -1;
            while(nums[j]<=nums[i-1]) j--;
            swap(nums[j], nums[i-1]);
        }
        reverse(nums.begin()+i,nums.end());
    }
};
