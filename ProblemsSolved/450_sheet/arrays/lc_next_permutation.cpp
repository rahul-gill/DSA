#include<bits/stdc++.h>
using namespace std;

/**
 * - for descending order permutation, no next larger permutation is possible.
 * - So we need to find first pair of elements from the right {a[i], a[i-1]}, which satisfy a[i−1] < a[i]
 *   1 5 8 4 7 6 5 3 1
 *         ^
 *        i-1
 * - Now to find next permutation, we'll have to rearrange the sub array a[i-1 : a.size() - 1]'s elements, for that:
 * 1. We need to replace the number a[i−1] with the number which is just larger than itself among the numbers lying to its right section(call this number d)
 *   1 5 8 4 7 6 5 3 1
 *         ^     ^
 *        i-1    d
 *    modified array: 1 5 8 5 7 6 4 3 1
 * 2. then we'll reverse the sub array a[i: a.size()-1]
 *   1 5 8 5 1 3 4 6 7
 * https://leetcode.com/media/original_images/31_Next_Permutation.gif
 */

bool nextPermutation(vector<int>& nums) {
    int i=nums.size()-1;
    while(i>0 && nums[i]<=nums[i-1])
        --i;

    if(i>0) {
        int j = nums.size() -1;
        while(nums[j]<=nums[i-1]) 
            j--;
        swap(nums[j], nums[i-1]);
    }
    else 
        return 0;
    reverse(nums.begin()+i,nums.end());
    return 1;
}
