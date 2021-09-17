#include<bits/stdc++.h>
using namespace std;

int k;
string comm_chars[5];
char grida[6][5], gridb[6][5];
string pass,curPassword;
int passNum=0;
void solve(int col = 0){
	if(pass != "") return;
	if(col == 5) {
		passNum++;
		if(passNum == k) pass = curPassword;
		return;
	}
	for(int i=0;i<comm_chars[col].size();i++){
		curPassword += comm_chars[col][i];
		solve(col+1);
		curPassword.pop_back();
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>k;
		for(int i=0;i<6;i++){
			string s;
			cin>>s;
			for(int j=0;j<5;j++) grida[i][j] = s[j];
		}
		for(int i=0;i<6;i++){
			string s;
			cin>>s;
			for(int j=0;j<5;j++) gridb[i][j] = s[j];
		}
		for(int i=0;i<5;i++) comm_chars[i].clear();
		for(int c=0;c<5;c++){
			for(int r1=0;r1<6;r1++){
				for(int r2=0;r2<6;r2++){
					if(grida[r1][c] == gridb[r2][c]) comm_chars[c].push_back(gridb[r2][c]);
				}
			}
		}
		for(int i=0;i<5;i++){
			sort(comm_chars[i].begin(), comm_chars[i].end());
			comm_chars[i].erase(unique(comm_chars[i].begin(), comm_chars[i].end()), comm_chars[i].end());
		}
		pass = "";
		passNum = 0;
		curPassword.clear();
		solve();
		if(pass == "") cout<<"NO\n";
		else cout<<pass<<'\n';
	}
}