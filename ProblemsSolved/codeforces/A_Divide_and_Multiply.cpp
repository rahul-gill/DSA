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
    vector<int> arr(n);
    for(auto &x: arr) cin>>x;

    int k = 0;
    for(auto &x:arr){
        while(x % 2 == 0) x /= 2, k++;
    }

    int max_indx = 0, maxi = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            max_indx = i;
        }
    }
    long long res = 0;
    for(int i=0; i<n; i++){
        if(i != max_indx) res += arr[i];
        else res += (arr[i]*(1ll<< k));
    } 
    cout<<res<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

