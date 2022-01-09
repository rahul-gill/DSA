#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   static  bool vectorSort(vector<int> a, vector<int> b){
        if(a[0] >= b[0]) return 0;
        else return 1;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), vectorSort);

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