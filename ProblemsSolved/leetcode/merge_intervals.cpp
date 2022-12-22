#include<cp_debug.h>

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    res.push_back(intervals.front());
    for(int i=1; i<intervals.size(); ++i){
        if(res.back().back() < intervals[i].front())
            res.push_back(interval[i]);
        else
            res.back().back() = max(res.back().back(), intervals[i].back());
    }

    return res;
}

int main(){
    vector<vector<int>> a{ {1,11}, {2,6}, {8,10}, {15,18} };

    debug(merge(a));
}
