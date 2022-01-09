#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
        string s, t;
        int occurs[26];
        cin>>s>>t;
        for(int i=0; i<26; i++) occurs[i] = 0;
        for(auto x:s) occurs[x - 'a']++;


        string res(s.size(), 'a'); 
        int x = 0, i=0, done = 0;
        int aoccurs = occurs[0], boccurs = occurs[1];
        while(i<26){
            while (occurs[i]--)
                res[x++] = 'a' + i;
            if(t == "abc" && aoccurs != 0 && boccurs != 0){
                if(i == 0 && !done) i = 2, done = 1;
                else if(i == 1 && done) i = 3; 
                else if(i == 2) i = 1;
                else i++;
            }
            else i++;
        }
        cout<<res<<'\n';
	}

}
