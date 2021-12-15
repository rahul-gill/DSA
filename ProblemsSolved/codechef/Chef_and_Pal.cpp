#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
        int n;
        cin>>n;
        if(n % 2 == 1) cout<<"-1\n";
        else{
            string s(n,'0');
            for(int i=0,j=n-1; i<j; i++,j--){{
                s[i] = '1';
            }}
            cout<<s<<'\n';
        }
	}
}
