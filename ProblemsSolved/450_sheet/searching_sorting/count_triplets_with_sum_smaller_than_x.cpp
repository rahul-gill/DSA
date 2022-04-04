#include<bits/stdc++.h>
using namespace std;


/**
 * Given an array arr[] of distinct integers of size N and a value sum, 
 * the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.
 */


long long countTriplets(long long arr[], int n, long long sum){
    sort(arr, arr+n);

    int cnt = 0;

    for(int i=0; i<n; i++){
        int l = i+1, r = n-1;
        while(l<r){
            long long sumHere = arr[i] + arr[l] + arr[r];

            if(sumHere < sum){
                cnt += r - l;
                l++;
            }
            else
                r--;
        }
    }
    return cnt;
}



int main(){
    long long arr[] = {-2,0,1,3};
    cout<<countTriplets(arr, 4,2);
}
