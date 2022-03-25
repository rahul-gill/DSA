#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array arr[] denoting heights of N towers and a positive integer K,
 * you have to modify the height of each tower either by increasing or decreasing them by K only once.
 * After modifying, height should be a non-negative integer.
 * Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.
 * Note: It is compulsory to increase or decrease (if possible) by K to each tower.
 *
 * Concept: traverse the array after sorting:
 *      - to minimize the difference between max and min element, max and min elements should be closest to each other
 *      - so we try to do that:
 *          we decrease arr[i+1] by k and increase arr[i] by k(also increase arr[0] by k and arr[n-1])
 *          also we make sure arr[i+1] isn't negative(heights must be positive)
 *
 * After sorting the array, the difference between min & max is arr.back() - arr.front()
 * To minimize this difference we have to change the min and max of the array
 * Since we can only modify elements by adding or subtracting k from them,
 *  our best bet is is to decrease the larger numbers and increase the smaller number and check if that has minimized the difference
 * In an array for example: 1, 4, 6, 5, 10, 14 we do the above with k = 3 and it becomes 4, 7, 8, 7, 11 the difference reduced from 13 to 7
 * Here we added 3 to 2nd element 4, If we're still not able to get there, we can try increasing the elements on right side of 2nd element
 * Similarly we can try decreasing the elements on left of the last decreased element
 * Since its compulsory to increase/decrease all elements we increase & decrease adjacent elements
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