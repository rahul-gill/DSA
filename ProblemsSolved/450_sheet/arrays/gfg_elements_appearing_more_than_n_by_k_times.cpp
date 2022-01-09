#include<bits/stdc++.h>
using namespace std;

vector<int> findThoseElements(vector<int> arr,int k){
    int nbyk = arr.size() / k;
    unordered_map<int, int> m;
    for(auto x:arr) m[x]++;
    
    vector<int> ans;
    for(auto x = m.begin(); x != m.end(); ++x)
        if(x->second > nbyk) ans.push_back(x->first); 
    return ans;
}