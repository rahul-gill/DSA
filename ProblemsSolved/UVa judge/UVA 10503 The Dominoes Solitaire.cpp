#include<bits/stdc++.h>
using namespace std;

int n,m;
typedef struct piece{ int l,r; 
	piece(int l,int r):l(l),r(r){}
	piece(){;} 
	piece reverse(){ piece temp(r,l); return temp;}
	}piece;
vector<piece> line,pieces;
vector<bool> choosen;
bool ans;
void solve(int depth = 1){
	if(depth == n+1 || ans == 1) { ans = 1;return; }
	for(int i=0;i<m && !ans;i++){
		if(choosen[i]) continue;
		choosen[i] = 1;
		if((depth == n && line[depth-1].r == pieces[i].l && pieces[i].r == line[n+1].l) || depth!=n && line[depth-1].r == pieces[i].l){
			line[depth] = pieces[i];
			solve(depth+1);
		}
		else if((depth == n && line[depth-1].r == pieces[i].r && pieces[i].l == line[n+1].l) || depth!=n && line[depth-1].r == pieces[i].r){
			line[depth] = pieces[i].reverse();
			solve(depth+1);
		}
		choosen[i] = 0;
	}
}

int main(){
	while(cin>>n && n){
		cin>>m;
		line = vector<piece>(n+2);
		pieces = vector<piece>(m);
		choosen = vector<bool>(m,0);
		cin>>line[0].l>>line[0].r;
		cin>>line[n+1].l>>line[n-1].r;
		for(int i=0;i<m;i++)
			cin>>pieces[i].l>>pieces[i].r;
		ans = 0;
		solve();
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";

	}
}