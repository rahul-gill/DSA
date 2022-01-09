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
    vector<int> p(n), q(n);
    for(int i=0; i<n; i++) q[i] = i+1;
    for(int i=0; i<n; i++){
        cout<< "? " << i+1<<endl<<endl;
        int qi;
        cin>>qi;
        cout<< "? " << i+1<<endl<<endl;
        cin>>p[qi-1];
    }
    cout<< "!";
    for(auto x: p) cout<<" "<<x;
    cout<<endl<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

