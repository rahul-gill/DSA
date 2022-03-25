#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
 * Find the minimum number of jumps to reach the end of the array (starting from the first element).
 * If an element is 0, then you cannot move through that element.
 * Note: Return -1 if you can't reach the end of the array.
 *
 * Concept: mxreach tracks maximum reach index
 *          step tracks steps we can make with current elements
 *          jumps track number of jumps(if steps are zero, then we have to make a jump)
 */

int minJumps(int arr[], int n){
    if(n==0 || n==1) return 0;
    if(arr[0] == 0) return -1;

    int mxrech=arr[0], step=arr[0], jump=0;

    for(int i=1;i<n-1;i++){
        //we took a step further
        step--;
        //update our max reach
        mxrech=max(mxrech,arr[i]+i);

        //if we can't take a step further then we have to make a jump
        if(step==0){
            jump++;
            step=mxrech-i;
            if(step <= 0) return -1;
        }
    }
    return jump+1;
}
   