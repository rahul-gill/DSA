#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 * Used technique: negate the traversed number, if  any coming number is negative, its the duplicate(since original elements are in [1, n])
 */

int findDuplicate(vector<int>& nums) {
    for(int &x: nums){
        if(nums[abs(x)-1] < 0){
            return abs(x);
        }
        nums[abs(x) - 1] *= -1;
    }
    return 0;
}