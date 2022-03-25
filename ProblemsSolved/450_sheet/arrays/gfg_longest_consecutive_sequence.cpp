#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of integers,
 * find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
 * the consecutive numbers can be in any order.
 */

int findLongestConseqSubseq(int arr[], int n){
    unordered_set<int> S(arr, arr + n);
    int ans = 0;

    // For every element of array
    for(int i = 0; i < n; i++){
        // If integer before the element in consecutive integer order is not in array
        if (S.find(arr[i] - 1) == S.end()){
            //Count how many number coming after the element are present in the array
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
            // We have to find the longest consecutive sub-sequence
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++) cin>>arr[i];
    cout<<findLongestConseqSubseq(arr, N);


    
}