#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of integers and another number. 
 * Find all the unique quadruple from the given array that sums up to the given number.
 */

vector<vector<int> > fourSum(vector<int> &arr, int kk) {
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;

    for(int i=0; i<arr.size()-3; i++)
        for(int j=i+1; j<arr.size()-2; j++){
            
            int l = j+1, r = arr.size() - 1;
            
            while(l < r){
                int sum = arr[i] + arr[j] + arr[l] + arr[r] ; 
                
                if(sum == kk){
                    ans.insert(vector<int>{arr[i], arr[j], arr[l], arr[r]});
                    int left_val = arr[l], right_val = arr[r];
                    while(arr[l] == left_val) l++;
                    while(arr[r] == right_val) r--;
                }
                else if(sum < kk) 
                    l++;
                else 
                    r--;
            }
        }
    
    vector<vector<int>> a;
    for(auto x:ans) a.push_back(x);
    return a;
}
