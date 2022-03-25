#include<bits/stdc++.h>
using namespace std;

/**
 * Find if sub-array of zero sum exists
 *
 * If we consider all prefix sums, we can notice that there is a subarray with 0 sum when :
 * - Either a prefix sum repeats or
 * - Or prefix sum becomes 0.
 * Prefix sums for {1, 4, -2, -2, 5, -4, 3} array are:
 * 1, 5, 3, 1, 6, 2, 5
 * Since prefix sum 1 repeats, we have a subarray with 0 sum.
 */

bool subArrayExists(int arr[], int n){
    vector<int> prefixSumArr(n);
    prefixSumArr[0] = arr[0];
    for(int i=1; i<n; i++) prefixSumArr[i] = prefixSumArr[i-1] + arr[i];

    unordered_set<int> prefixSums;
    for(auto x:prefixSumArr){
        if(x == 0 || prefixSums.find(x) != prefixSums.end()) return 1;
        prefixSums.insert(x);
    }
    return 0;
}
