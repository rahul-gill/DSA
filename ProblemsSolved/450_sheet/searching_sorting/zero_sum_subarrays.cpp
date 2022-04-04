#include<bits/stdc++.h>
using namespace std;


long long findSubarray(vector<long long> arr, int n){

    unordered_map<long long, vector<int> > map;
    vector <pair<int, int>> ans;
    int sum = 0;
  
    for (int i = 0; i < n; i++){
        sum += arr[i];
  
        if (sum == 0)
            ans.push_back(make_pair(0, i));
  
        if (map.find(sum) != map.end()){
            for(int index: map[sum]){
                ans.push_back(make_pair(index+1, i));
            }
        }
  
        map[sum].push_back(i);
    }
  
    return ans.size();
}

