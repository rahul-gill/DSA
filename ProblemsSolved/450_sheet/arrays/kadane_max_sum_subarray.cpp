#include<bits/stdc++.h>
using namespace std;

/**
 * Concept: Kadane's algorithm
 */

int ans1, ans2;
void maxSubarraySum(int arr[], int n){
	int sum = 0, maxi = arr[0];

    //these variables for the location of maximum sum sub-array
	int mssBegin=0, mssEnd=0, currentBegin=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum>maxi){
			maxi = sum;
			mssBegin = currentBegin;
			mssEnd = i+1;
		}
		if(sum<0){
			sum = 0;
			currentBegin = i;
		}
	}

    ans1 = mssBegin;
    ans2 = mssEnd;
    return maxi;
}
