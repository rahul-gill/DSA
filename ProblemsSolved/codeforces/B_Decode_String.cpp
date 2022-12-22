#ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    using namespace std;
    #define debug(...) 42
#else
    #include "cp_debug.h"
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        string res;
        for(int i=n-1; i>=0; ){
            if(s[i] == '0'){
                int num = (s[i-1]-'1' + (s[i-2]-'0')*10); 
                res += ('a' + num);
                debug(i, res.back() - 'a');
                i -= 3;
            }
            else{
                res += 'a' + (s[i]-'1');
                debug(i, res.back() - 'a');
                --i; 
            }
        }
        for(int i=res.size()-1; i>=0; --i)
            cout<<res[i];
        cout<<'\n';
    }
}
