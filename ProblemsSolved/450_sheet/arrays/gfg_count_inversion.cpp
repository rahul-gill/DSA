#include<bits/stdc++.h>
using namespace std;

/**
 * Inversion Count for an array indicates:
 * how close the array is from being sorted.
 * Formally speaking, two elements a[i] and a[j] of array a form an inversion if a[i] > a[j] and i < j
 * Example:
 *  Array: {8, 4, 2, 1}
 *  Inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1) total 6
 */


/**
 * Modified merge sort way: when merging we count how many elements of right array are greater than those of left array
 */

long long merge(long long arr[], long long l, long long m, long long r){
    long long n1 = m-l+1, n2 = r-m;
    long long ans = 0;

    long long larr[n1], rarr[n2];
    copy(arr, arr + n1, larr);
    copy(arr + n1, arr + n1 + n2, rarr);

    long long i=0,j=0,k=l;
    while (i < n1 and j < n2){
        if(larr[i] <= rarr[j])
            arr[k] = larr[i++];
        else{
            arr[k] = rarr[j++];
            ans+= n1-i;
        }
        k++;
    }
    while (i!= n1) arr[k++] = larr[i++];
    while (j!= n2) arr[k++] = rarr[j++];
    return ans;
    
}
long long inversionCount(long long arr[], long long l, long long r){
    long long mid = (l+r)/2;
    long long ret = 0;
    if(l<r){
        ret += inversionCount(arr, l, mid);
        ret += inversionCount(arr, mid+1, r);
        ret += merge(arr,l,mid,r);
    }
    return ret;
}

/**
 * using sets
 */
long long getInvCount(long long  arr[],long long n) {
    
    int inversion_count = 0;

    multiset<long long>::iterator it;

    multiset<long long> setX;
    
    setX.insert(arr[0]);
    
    for (int i=1; i<n; i++){
        setX.insert(arr[i]);

        // Set the iterator to first greater element than arr[i]
        // in set (Note that set stores arr[0],.., arr[i-1]
        it = setX.upper_bound(arr[i]);

        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of arr[i]
        inversion_count += distance(it, setX.end());
    }

    return inversion_count;
}

int main(){
    long long N =6,arr[] = {5,6,6,1,2,3};
    cout<<inversionCount(arr, 0, N-1);
}