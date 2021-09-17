#include<bits/stdc++.h>
using namespace std;

#define MAXSTN 4100000
#define UP_SET 1
#define UP_CLR 2
#define UP_FLP 3
 
int st[MAXSTN], U[MAXSTN], n;
bool A[1024005];
void inputing(){
	int m,f,i=0;
	string s;
	cin>>m;
	while(m--){
		cin>>f>>s;
		while(f--){
			for(auto x: s) A[i++] = x - '0'; 
		}
	}
	n = i;
}
int build(int p, int a, int b){
	U[p] = 0;
	if(a == b) return st[p] = A[a];
	int l = p<<1, r = l+1, mid = (a+b)/2;
	int vall = build(l,a,mid), valr = build(r,mid+1,b);
	st[p] = vall+valr;
	return st[p];
}
//////////////////////////////////////////////////////////////////////
int apply_flip(int v) {
        if (v == UP_SET) return UP_CLR;
        if (v == UP_CLR) return UP_SET;
        if (v == UP_FLP) return 0;
        return UP_FLP;
}
void propagate(int p, int a,int b){
	if (U[p] == 0) return;
     if (U[p] == UP_SET) st[p] = b - a + 1;
     else if (U[p] == UP_CLR) st[p] = 0;
     else if (U[p] == UP_FLP) st[p] = (b - a + 1) - st[p];
 	if (a != b){
     	int lt = 2*p, rt = lt + 1;
     	if (U[p] == UP_SET || U[p] == UP_CLR) U[lt] = U[rt] = U[p];
          else {U[lt] = apply_flip(U[lt]); U[rt] = apply_flip(U[rt]);}
     }
     U[p] = 0;
}
void setu(int i, int j, int p, int a,int b){
	propagate(p,a,b);
	if(a > j || b<i) return;
	if(a==b) {st[p] = 1;return;}
	int l = p<<1, r = l+1, mid = (a+b)/2;
	if(a>=i && b<=j){
		st[p] = b-a+1;
		U[l] = U[r] = UP_SET;
		return;
	} 
	setu(i,j,l,a,mid);
	setu(i,j,r,mid+1,b);
	st[p] = st[l] + st[r];
}
void unsetu(int i, int j, int p, int a,int b){
	propagate(p,a,b);
	if(a > j || b<i) return;
	if(a==b) {st[p] = 0;return;}
	int l = p<<1, r = l+1, mid = (a+b)/2;
	if(a>=i && b<=j){
		st[p] = 0;
		U[l] = U[r] = UP_CLR;
		return;
	} 
	unsetu(i,j,l,a,mid);
	unsetu(i,j,r,mid+1,b);
	st[p] = st[l] + st[r];
}
void flp(int i, int j, int p, int a,int b){
	propagate(p,a,b);
	if(a > j || b<i) return;
	if(a==b) {st[p] = (st[p] == 1 ? 0 : 1); return;}
	int l = p<<1, r = l+1, mid = (a+b)/2;
	if(a>=i && b<=j){
		st[p] = b-a+1 - st[p];
		U[l] = apply_flip(U[l]);
		U[r] = apply_flip(U[r]);
		return;
	} 
	flp(i,j,l,a,mid);
	flp(i,j,r,mid+1,b);
	st[p] = st[l] + st[r];
}
int qr(int i, int j, int p, int a,int b){
	propagate(p,a,b);
	if(a > j || b<i) return -1;
	if(a>=i && b<=j) {return st[p];}
	int l = p<<1, r = l+1, mid = (a+b)/2;
	int vall = qr(i,j,l,a,mid);
	int valr = qr(i,j,r,mid+1,b);
	if(vall < 0) return valr;
	if(valr < 0) return vall;
	return valr + vall;	
}/////////////////////////////////////////////////////////////////////
void setting(int i,int j){ setu(i, j,1, 0,n-1); }
void unsetting(int i,int j){ unsetu(i, j,1, 0,n-1); }
void flipping(int i,int j){ flp(i, j,1, 0,n-1); }
int querring(int i,int j){ return qr(i, j,1, 0,n-1); }

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t,tn=0;
	cin>>t;
	while(tn++ < t){
		cout<<"Case "<<tn<<":\n";
		inputing();
		build(1,0,n-1);
		int q,indx = 1;
		cin>>q;
		while(q--){
			char ch;int x, y;
			cin>>ch>>x>>y;
			if(ch == 'F') {setting(x,y);}
			else if(ch == 'E') {unsetting(x,y);}
			else if(ch == 'I') {flipping(x,y);}
			else if(ch == 'S') cout<<"Q"<<(indx++)<<": "<<querring(x,y)<<'\n';
		}
	}
} 

