#include<bits/stdc++.h>
using namespace std;

int main(){
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int t;
	while(cin>>t){
		int maxx = t*(t+1);
		vector<pair<int,int>> lists;
		for(int i=t+1;i<=t*2;i++){
			if((t*i) % (-t + i) == 0) lists.push_back(make_pair((t*i) / (-t + i),i));
		}
		cout<<lists.size()<<'\n';
		for(auto x:lists){
			printf("1/%d = 1/%d + 1/%d\n",t,x.first,x.second);
		}
	}

} 

