#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
 * of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 */

int minSubArrayLen(int target, vector<int>& nums) {
    long long sum_upto_now = 0;    
    int l = 0, ans = INT_MAX;

    for(int i=0; i<nums.size(); ++i){
        sum_upto_now += nums[i];
        if(sum_upto_now >= target){
            // this  is for this kind of case: array = {1,2,10}, target = 5
            while(sum_upto_now - nums[l] >= target)
                sum_upto_now -= nums[l++];
            ans = min(i-l+1, ans);
        } 
    }
    return (ans==INT_MAX) ? 0 : ans;
}

int main(){
    vector<int> a{10,2,3};
    int target = 6;
    cerr<<minSubArrayLen(target, a); 
}
