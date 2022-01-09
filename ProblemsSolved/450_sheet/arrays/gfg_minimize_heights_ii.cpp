#include<bits/stdc++.h>
using namespace std;

/*
 * Concept: traverse the array after sorting:
 *      - to minimize the difference between max and min element, max and min elements should be closest to each other
 *      - so we try to do that:
 *          we decrease arr[i+1] by k and increase arr[i] by k(also increase arr[0] by k and arr[n-1])
 *          also we make sure arr[i+1] isn't negative(heights must be positive)
 */

int getMinDiff(int arr[], int n, int k) {

    sort(arr, arr+n);
    int ans = arr[n-1] - arr[0];

    for(int i = 0; i < n-1; i++) {
        if(arr[i+1] < k) continue;
        int currMin = min(arr[i+1]-k, arr[0]+k);
        int currMax = max(arr[i]+k, arr[n-1]-k);
        ans = min(ans, currMax-currMin);
    }

    return ans;
}