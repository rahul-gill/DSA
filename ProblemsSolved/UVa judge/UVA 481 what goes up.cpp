#include<bits/stdc++.h>
using namespace std;

int res[1000000],v[1000000],res_id[1000000],P[1000000];

void print(int fin){ 
	if(fin<0) return;
	print(P[fin]);
	cout<<v[fin]<<'\n'; 
}
int main(){
	int resSize= 0,resEnd = 0;
	for(int i=0;;i++){
		if(!(cin>>v[i])) break;

		int pos = lower_bound(res,res+resSize,v[i]) - res;
		res[pos] = v[i];
		res_id[pos] = i;
		if(pos == resSize) {resSize++; resEnd = i;}

		P[i] = pos>0 ? res_id[pos-1] : -1;
	}
	printf("%d\n-\n",resSize);
	print(resEnd);
}