#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        // sort intervals based on their starting index
        sort(
            intervals.begin(),
            intervals.end(),
            [](vector<int> a, vector<int> b){ return (a[0] < b[0]); }
        );

        vector<vector<int>> ret;
        ret.push_back(intervals[0]);

        for(auto x: intervals){
            auto &lastTracking = ret.back();
            if(x[0] <= lastTracking[1]){
                int endPoint = max(x[1],lastTracking[1]);
                lastTracking[1] = endPoint;
            }else
                ret.push_back(x);
        }
        return ret; 
    }
};