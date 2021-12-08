#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;
        int diff = 0;
        for(auto i: s){
            if(i == '1') diff++;
            else if(i == '0') diff--;
        }
        bool change = 0;
        for(auto &i: s) if(i == '?'){
            if(diff > 0)
                i = '0', diff--;
            else if(diff < 0)
                i = '1', diff++;
            else{
                i = (change)? '0' : '1';
                change = !change;
            }
        }
        cout<<s<<"\n";
    }
}