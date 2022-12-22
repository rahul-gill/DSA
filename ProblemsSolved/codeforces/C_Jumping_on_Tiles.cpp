#ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    using namespace std;
    #define debug(...) 42
#else
    #include "cp_debug.h"
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char, vector<int>> val_to_idx;
        for(int i=1; i<s.size()-1; ++i)
            val_to_idx[s[i]].push_back(i);
        
        
        auto beg = val_to_idx.lower_bound(min(s.back(),s.front()));
        auto end = val_to_idx.upper_bound(max(s.back(),s.front()));
    
        int sz = 0;
        vector<string> vec;
        for(; beg != end; ++beg){
            sz += beg->second.size();
            for(int i=0; i<beg->second.size(); ++i)
                vec.push_back(to_string(beg->second[i] + 1));
        }

        cout<<abs(s.back() - s.front())<<' '<<sz+2<<'\n';
        cout<<"1 ";
        if(s.front() < s.back()){
            for(auto &x: vec)
                cout<<x<<' ';
        }
        else{
            for(int i=vec.size()-1; i>=0; --i)
                cout<<vec[i]<<' ';
        }
        cout<<s.size()<<'\n';
    }
}
