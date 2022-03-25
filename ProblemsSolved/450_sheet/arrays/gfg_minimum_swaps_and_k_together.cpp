#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of n positive integers and a number k.
 * Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
 */

int minSwap(int arr[], int n, int k) {
    if(n <= 2) return 0;
    
    int wnd = 0, cnt = 0;
    for(int i=0; i<n; i++)
        if(arr[i] <= k) wnd++;

    for(int i=0; i<wnd; i++)
        if(arr[i] > k) cnt++;

    int ans = cnt;

    //We check every window of length wnd, that require minimum swaps to do the task
    for(int i=1; i<= n-wnd; i++){
        //With these two if blocks we update the required swaps for next window from previous window
        if(arr[i-1] > k) cnt--;
        if(arr[i+wnd-1] > k) cnt++;

        ans = min(ans, cnt);
    }
    return ans;
}

