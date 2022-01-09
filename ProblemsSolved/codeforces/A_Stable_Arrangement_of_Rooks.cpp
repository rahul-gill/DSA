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
    int n,k;
    cin>>n>>k;
    if(k > (n+1)/2){
        cout<<"-1\n";
        return;
    }
    int cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j && i % 2 == 0 && cnt <= k){
                 cout<<'R';
                 cnt++;
            }
            else cout<<'.';
        }
        cout<<'\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

