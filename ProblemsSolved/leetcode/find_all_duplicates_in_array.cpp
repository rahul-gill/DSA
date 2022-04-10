#include<bits/stdc++.h>
using namespace std;

/**
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
 * return an array of all the integers that appears twice.
 * You must write an algorithm that runs in O(n) time and uses only constant extra space.
 */

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    
    int n = nums.size();

    for(int i=0; i<n; i++){
        int val = abs(nums[i]);
        if(nums[val - 1] < 0)
            duplicates.push_back(val);

        nums[val - 1] *= -1;
    }

    return duplicates;
}


int main(){
    vector<int> a{4,3,2,7,8,2,3,1};
    for(auto &x: findDuplicates(a))
        cout<<x<<' ';

}
