#define LOCAL
#ifdef LOCAL
	#include "cp_debug.h" 
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#include<bits/stdc++.h>
	using namespace std;
	#define debug(...) 42
#endif

int arr[32000], arr2[1100];

void solve(){
    int n;
    cin>>n;
    unordered_set<int> likes;
    for (int i=0; i<32000 && arr[i] <= n; i++){
        likes.insert(arr[i]);
    }
    for (int i=0; i<1100 && arr2[i] <= n; i++){
        likes.insert(arr2[i]);
    }
    cout<<likes.size()<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    for(int i=0; i<32000; i++){
        arr[i] = (i+1)*(i+1);
    }
    for(int i=0; i<1100; i++){
        arr2[i] = (i+1)*(i+1)*(i+1);
    }

	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

