#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of n distinct elements. 
 * Find the minimum number of swaps required to sort the array in strictly increasing order.
 */

int minSwaps(vector<int>&nums){
    vector<pair<int,int>> numsToIndex;
    
    for(int i=0; i<nums.size(); i++)
        numsToIndex.push_back({nums[i], i});

    sort(numsToIndex.begin(), numsToIndex.end());

    int cnt = 0;

    for(int i=0; i<nums.size(); i++)
        if(i != numsToIndex[i].second){
            cnt++;
            swap(numsToIndex[i], numsToIndex[numsToIndex[i].second]);
            i--;
        }

    return cnt;
}

