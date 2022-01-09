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
    int n,x;
    cin>>n>>x;
    vector<bool> place_taken(101);
    for(int i=0; i<n; i++){
        int xx;
        cin>>xx, place_taken[xx] = 1;
    } 
    int places = 0;
    for(int i=1; i<101; i++){
        if(place_taken[i]) places++;
        else if(x > 0) places++,x--;
        else break; 
    }
    while (x --> 0)
        places++; 
    cout<<places<<'\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

