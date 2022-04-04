#include<bits/stdc++.h>
using namespace std;
/**
 * Given an array nums[] of size n, construct a Product Array P (of same size n) 
 * such that P[i] is equal to the product of all the elements of nums except nums[i].
 * do this without division 
 */

vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {

    vector<long long int> left(n), right(n), prod(n);
    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++)
        left[i] = arr[i-1] * left[i-1];

    for(int i=n-2; i>=0; i--)
        right[i] = arr[i+1] * right[i+1];

    for(int i=0; i<n; i++)
        prod[i] = left[i] * right[i];

    return prod;

}
