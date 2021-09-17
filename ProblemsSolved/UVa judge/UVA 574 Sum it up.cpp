#include<bits/stdc++.h>
using namespace std;

int t,n,sum;
vector<int> arr;
vector<int> solution;
vector<vector<int>> solutions;


void solve(int depth = 0){
	if(sum == t ){
		solutions.push_back(solution);
		return;
	}
	if(sum > t) return;
	if(depth == n) return;
	solution.push_back(arr[depth]);
	sum += arr[depth];
	solve(depth+1);
	sum -= arr[depth];
	solution.pop_back();
	solve(depth+1);
}

int main(){
	while(cin>>t>>n && t>0){
		arr = vector<int>(n);
		for(auto &x:arr) cin>>x;
		solutions.clear();
		sort(arr.rbegin(), arr.rend());
		sum = 0;
		solve();
		sort(solutions.begin(), solutions.end(), greater<vector<int>>());
		auto last = unique(solutions.begin(),solutions.end());
		solutions.erase(last,solutions.end());
		printf("Sums of %d:\n",t);
		if(solutions.size() == 0) { printf("NONE\n");continue;}
		for(auto x:solutions){
			for(int i = 0; i<x.size();i++) printf(i==x.size()-1? "%d":"%d+",x[i]);
			printf("\n");
		}
	}	
}