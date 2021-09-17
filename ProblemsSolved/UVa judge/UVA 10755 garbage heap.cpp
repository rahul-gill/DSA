#include<bits/stdc++.h>
using namespace std;

int a,b,c;
long long field[21][21][21];

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		for(int i=0;i<a;i++) for(int j=0;j<b;j++) for(int k=0;k<c;k++){
			cin>>field[i][j][k];
			if(i>0) field[i][j][k] += field[i-1][j][k];
			if(j>0) field[i][j][k] += field[i][j-1][k];
			if(k>0) field[i][j][k] += field[i][j][k-1];
			if(i>0 && j>0) field[i][j][k] -= field[i-1][j-1][k];
			if(i>0 && k>0) field[i][j][k] -= field[i-1][j][k-1];
			if(j>0 && k>0) field[i][j][k] -= field[i][j-1][k-1];
			if(i>0 && j>0 && k>0) field[i][j][k] += field[i-1][j-1][k-1];
		}
		long long maxEntry = LONG_LONG_MIN;
		
		for(int i=0;i<a;i++) for(int j=0;j<b;j++) for(int k=0;k<c;k++)
		for(int l=i;l<a;l++) for(int m=j;m<b;m++) for(int n=k;n<c;n++){
			long long entry = field[l][m][n];
			if(i>0) entry -= field[i-1][m][n];
			if(j>0) entry -= field[l][j-1][n];
			if(k>0) entry -= field[l][m][k-1];
			if(i>0 && j>0) entry += field[i-1][j-1][n];
			if(i>0 && k>0) entry += field[i-1][m][k-1];
			if(j>0 && k>0) entry += field[l][j-1][k-1];
			if(i>0 && j>0 && k>0) entry -= field[i-1][j-1][k-1];
			maxEntry = max(maxEntry,entry);
		}	
		
		cout<<maxEntry<<'\n';
		if(t) cout<<'\n';
	}
	
}