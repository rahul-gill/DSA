#include<bits/stdc++.h>
using namespace std;

/*
 * Concept: mxreach tracks maximum reach index
 *          step tracks steps we can make with current elements
 *          jumps track number of jumps(if steps are zero, then we have to make a jump)
 */

int minJumps(int arr[], int n){
    if(n==0 || n==1) return 0;
    if(arr[0] == 0) return -1;

    int mxrech=arr[0];
    int step=arr[0];
    int jump=0;
    for(int i=1;i<n-1;i++){
        step--;
        mxrech=max(mxrech,arr[i]+i);
        if(step==0)
        {
            jump++;
            step=mxrech-i;
            if(step<=0)
                return -1;
        }
    }
    return jump+1;
}
   