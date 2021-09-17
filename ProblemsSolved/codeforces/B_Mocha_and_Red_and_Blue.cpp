#include<bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vector<pair<int,int>> data;
        bool going = false;
        for(int i=0; i<s.size(); i++){
            if(going){
                if(s[i] == '?'){
                    (data.end()-1) -> second = i;
                }else going = false;
            }else if(s[i] == '?') going = true,data.push_back({i,i});
        }
        for(int i=0; i<data.size(); i++){
            int leftIndex = data[i].first, rightIndex = data[i].second;
            char left = (leftIndex==0)?'C':s[leftIndex-1];
            char right = (rightIndex==s.size()-1)?'C':s[rightIndex+1];
            if(left == 'C' && right == 'C'){
                for(int i=leftIndex; i<=rightIndex; i++) s[i] = (i%2==0)?'R':'B';
            }else if(left == 'C'){
                char toFill = s[rightIndex+1];
                for(int i=rightIndex; i>=leftIndex; i--) {
                    toFill = (toFill == 'R')?'B':'R';
                    s[i] = toFill;
                }
                
            }else if(right == 'C'){
                char toFill = s[leftIndex-1];
                for(int i=leftIndex; i<=rightIndex; i++) {
                    toFill = (toFill == 'R')?'B':'R';
                    s[i] = toFill;
                }
            }else{
                char toFill = s[leftIndex-1];
                for(int i=leftIndex; i<=rightIndex; i++) {
                    //cout<<i<<','<<flush;
                    toFill = (toFill == 'R')?'B':'R';
                    s[i] = toFill;
                }
            }
        }
        cout<<s<<'\n';
    }
}
