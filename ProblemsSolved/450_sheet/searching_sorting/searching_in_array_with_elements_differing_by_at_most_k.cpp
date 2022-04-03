#include<bits/stdc++.h>
using namespace std;

/**
 * A step array is an array of integer where each element has a difference of at most k with its neighbor. 
 * Given a key x, we need to find the index value of x if multiple elements exist, return the first occurrence of the key. 
 */


/**
 * For example when k = 20, target = 100
 * when array element are exactly differ by k and arr = {70, 90, 110, 130}
 * then we can search the target by jumping the index by abs(arr[i] - x) / k
 * if some neighboring elements differ by less than k then we may have to make some more jumps
 */

int search(int arr[], int n, int x, int k){
    int i = 0;
    while (i < n){
        if (arr[i] == x)
            return i;

        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    return -1;
}

