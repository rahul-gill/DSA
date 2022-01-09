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
	
	vector<int> divs;
	int sqrtn = ceil(sqrt(n));
    for(int i=2; i<=sqrtn && divs.size() < k; i++){
		while(n % i == 0 && divs.size() < k-1){
			n/=i;
			divs.push_back(i);
		}
    }
	if(divs.size() == k-1 && n != 1){
		divs.push_back(n);
		for(auto x: divs) cout<<x<<' ';
	}
	else cout<<"-1"; 
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	//cin>>tc;
	while(tc--) solve();
}

