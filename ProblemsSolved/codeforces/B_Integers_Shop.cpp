#define LOCAL
#ifdef LOCAL
	#include "cp_debug.h" 
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#include<bits/stdc++.h>
	using namespace std;
	#define debug(...) 42
#endif

void solve(){
    int n;
    cin>>n;
    vector<int> l,r,c;
    for(int i=0; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        l.push_back(x);
        r.push_back(y);
        c.push_back(z);
    }

    map<int,int> lToIndex, rToIndex;
    for(int s=0; s<n; s++){
        int oldl = lToIndex[l[s]];
        int oldr = rToIndex[r[s]];
        int ans1, ans2, nums1, nums2;

        if(lToIndex.find(l[s]) != lToIndex.end()){
            if(c[ lToIndex[l[s]] ] > c[s])
                lToIndex[l[s]] = s;
        }
        else lToIndex.insert({l[s], s});
        if(rToIndex.find(r[s]) != rToIndex.end()){
            if(c[ rToIndex[r[s]] ] > c[s])
                rToIndex[r[s]] = s;
        }
        else rToIndex.insert({r[s], s});
    

        int minIndx = lToIndex.begin()->second;
        int maxIndx = (--rToIndex.end())->second;

        pair<int,int> minIndxlr = {l[minIndx], r[minIndx]};
        pair<int,int> maxIndxlr = {l[maxIndx], r[maxIndx]};
        if(minIndxlr.first <= maxIndxlr.first && minIndxlr.second >= maxIndxlr.second){
            ans1 = c[minIndx];
            nums1 = minIndxlr.second - minIndxlr.first;
        }   
        else if(minIndxlr.first >= maxIndxlr.first && minIndxlr.second <= maxIndxlr.second){
            ans1 = c[maxIndx];
            nums1 = maxIndxlr.second - maxIndxlr.first;
        }
        else if(minIndx == maxIndx){
            ans1 = c[minIndx];
            nums1 = minIndxlr.second - minIndxlr.first;
        }
        else{
             ans1 = c[minIndx] + c[maxIndx];
             nums1 = maxIndxlr.second - minIndxlr.first;
        }
        lToIndex[l[s]] = oldl;
        rToIndex[r[s]] = oldr;

        minIndx = lToIndex.begin()->second;
        maxIndx = (--rToIndex.end())->second;

        minIndxlr = {l[minIndx], r[minIndx]};
        maxIndxlr = {l[maxIndx], r[maxIndx]};
        if(minIndxlr.first <= maxIndxlr.first && minIndxlr.second >= maxIndxlr.second){
            ans2 = c[minIndx];
            nums2 = minIndxlr.second - minIndxlr.first;
        }   
        else if(minIndxlr.first >= maxIndxlr.first && minIndxlr.second <= maxIndxlr.second){
            ans2 = c[maxIndx];
            nums2 = maxIndxlr.second - maxIndxlr.first;
        }
        else if(minIndx == maxIndx){
            ans2 = c[minIndx];
            nums2 = minIndxlr.second - minIndxlr.first;
        }
        else{
            ans2 = c[minIndx] + c[maxIndx];
             nums2 = maxIndxlr.second - minIndxlr.first;
        
        }
        if(nums1 > nums2 || (nums1 == nums2 && ans2 < ans1)){
            cout<<ans1<<'\n';
            if(lToIndex.find(l[s]) != lToIndex.end()){
                if(c[ lToIndex[l[s]] ] > c[s])
                    lToIndex[l[s]] = s;
            }
            else lToIndex.insert({l[s], s});
        
            if(rToIndex.find(r[s]) != rToIndex.end()){
                if(c[ rToIndex[r[s]] ] > c[s])
                    rToIndex[r[s]] = s;
            }
            else rToIndex.insert({r[s], s}); 
        }
        else{
            cout<<ans2<<'\n';
        }

    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

