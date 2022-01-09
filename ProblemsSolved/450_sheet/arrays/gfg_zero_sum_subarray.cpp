#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n){
    vector<int> prefixSumArr(n);
    prefixSumArr[0] = arr[0];
    for(int i=1; i<n; i++) prefixSumArr[i] = prefixSumArr[i-1] + arr[i];

    unordered_set<int> prefixSums;
    for(auto x:prefixSumArr){
        if(x == 0 || prefixSums.find(x) != prefixSums.end()) return 1;
        prefixSums.insert(x);
    }
    return 0;
}
