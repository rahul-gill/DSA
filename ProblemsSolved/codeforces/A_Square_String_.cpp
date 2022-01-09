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
	string s;
	cin>>s;
	if(s.size() % 2 == 0 && s.substr(0,s.size()/2) == s.substr(s.size()/2, s.size()/2)) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

