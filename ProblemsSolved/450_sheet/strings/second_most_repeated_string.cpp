string secFrequent (string arr[], int n){
    unordered_map<string, int> f;
    int max_f = INT_MIN, max_f2 = INT_MIN;
    
    for(int i=0; i<n; ++i)
        max_f = max(max_f, ++f[arr[i]]);
    
    string ans;
    for(auto x: f){
        if(x.second > max_f2 && x.second < max_f){
            max_f2 = x.second;
            ans = x.first;
        }
    }
    
    return ans;
}
