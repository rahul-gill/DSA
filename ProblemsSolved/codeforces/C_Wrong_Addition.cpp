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
    string a,s;
    cin>>a>>s;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    vector<int> b;
    int k=0, i=0, j=0; 

    for(; i<a.size() && j<s.size(); i++, k++){
        if(a[i] - '0' > s[j] - '0'){
            if(s[j+1] != '1' || j+1 >= s.size()){ cout<<"-1\n"; return; }
            int twodig = (s[j+1] - '0') * 10 + s[j] - '0';
            b.push_back(twodig - (a[i] - '0'));
            j += 2;
        }
        else{
            b.push_back( int(s[j] - '0') - int(a[i] - '0'));
            j++;
        }
    }
    if(i != a.size()){ cout<<"-1\n"; return; }
    long long res = 0;
    long long mult = 1, tmp = j;
    for (int x = 0; x<j; x++) mult *= 10;
    while (j < s.size()){
        res +=  (s[j] - '0') * mult;
        j++;
        mult *= 10;
    }
    mult = 1;
    for(int i=0; i<b.size(); i++){
        res += b[i] * mult;
        mult *= 10; 
    }
    cout<<res<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int tc = 1;
  	cin>>tc;
	while(tc--) solve();
}

