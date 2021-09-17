#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> adj_list;
vector<bool> colors;
int bestDepth;
vector<bool> bestAns;

void solve(int depth = 0){
	if(depth > bestDepth) { 
		bestDepth = depth;
		bestAns = colors;
	}
	if(depth == n) return;
	for(int i=0; i<n; i++){
		if(!colors[i]) return;
		bool blackable = 1;
		for(auto x: adj_list[i]) blackable &= colors[x];
		if(blackable){
			colors[i]=0;
			solve(depth+1);
			colors[i] = 1;
		}
	}
}
bool vecCompare(vector<int> a, vector<int> b){
	if(a.size() > b.size()) return 0;
	else if(a.size() < b.size()) return 1;
	else return 1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;		
		adj_list.assign(n,vector<int>());
		colors.assign(n,1);
		bestDepth = 0;
		for(int i=0;i<k;i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			adj_list[a].push_back(b);
			adj_list[b].push_back(a);
		}
		solve();
		cout<<bestDepth<<'\n';
		bool first = 1;
		for(int i=0;i<bestAns.size();i++) {
			if(!bestAns[i]) {
				if(!first) cout<<' ';
				else first = 0; 
				cout<<(i+1);
			}
		}
		cout<<'\n';
	}
}