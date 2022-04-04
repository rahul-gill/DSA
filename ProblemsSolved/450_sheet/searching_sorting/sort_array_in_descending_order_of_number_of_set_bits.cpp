#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of integers, 
 * sort the array (in descending order) according to count of set bits in binary representation of array elements. 
 * Note: For integers having same number of set bits in their binary representation, 
 * sort according to their position in the original array i.e., a stable sort.
 */

void sortBySetBitCount(int arr[], int n){
    stable_sort(
        arr, 
        arr + n, 
        [](const int& a,const int& b) -> bool {
            return __builtin_popcount(a) >  __builtin_popcount(b);
        }
    );
}
