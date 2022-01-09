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
    long long a,b,c;
    cin>>a>>b>>c;
    if(a < c) cout<<"1 ";
    else cout<<"-1 ";

    if(b*a > c) cout<<b<<"\n";
    else cout<<"-1\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

