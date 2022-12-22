#include<cp_debug.h>



vector<vector<int>> insert(const vector<vector<int>>& intervals, vector<int>& newIntr) {
    vector<vector<int>> res;

    for(int i=0; i<intervals.size(); ++i){
        if(newIntr.back() < intervals[i].front()){
            res.push_back(newIntr);
            res.insert(res.end(), intervals.begin() + i, intervals.end());
        }
        else if(newIntr.front() > intervals[i].back())
            res.push_back(intervals[i]);
        else {
            newIntr.front() = min(newIntr.front(), intervals[i].front());
            newIntr.back() = max(newIntr.back(), intervals[i].back());
        }
        res.push_back(newIntr);
        return res;
    }
}
int main(){
    vector<vector<int>> a { {1,2}, {3,5}, {6,7}, {8,10}, {12,16} };
    debug(insert(a, vector<int>{4,8}));
}
