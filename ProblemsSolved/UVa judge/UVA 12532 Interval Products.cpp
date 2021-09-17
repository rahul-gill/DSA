#include<bits/stdc++.h>
using namespace std;
int A[100005], st[400005], n;
int val(int a){
	if(a==0) return 0;
	if(a>0) return 1;
	return -1;
}
void build(int p=1,int i=0, int j=n-1){
	if(i == j) {st[p] = val(A[i]);return;}
	int l = p<<1, r = l+1, mid = (i+j)/2;
	build(l,i,mid);
	build(r,mid+1,j);
	st[p] = st[l] * st[r];
}
void change(int index,int value,int p=1,int i=0, int j=n-1){
	if(i>index || j<index) return;
	if(i==j && j==index){ st[p] = val(value);return; }
	int l = p<<1, r = l+1, mid = (i+j)/2;
	change(index,value,l,i,mid);
	change(index,value,r,mid+1,j);
	st[p] = st[l] * st[r];
}
int qvery(int ql,int qr,int p=1,int i=0, int j=n-1){
	if(i>qr || j<ql) return 1;
	if(i>=ql && j<=qr) return st[p];
	int l = p<<1, r = l+1, mid = (i+j)/2;
	int ansl = qvery(ql,qr,l,i,mid);
	int ansr = qvery(ql,qr,r,mid+1,j);
	return ansl*ansr;
}
int main(){
	//cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int k;
	while(cin>>n){
		cin>>k;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		build();
		while(k--){
			char c;int a,b;
			cin>>c>>a>>b;
			if(c == 'C') change(a-1,b);
			else if(c == 'P') {
				int temp = qvery(a-1,b-1);
				if(temp>0) cout<<'+';
				else if(temp<0) cout<<'-';
				else cout<<'0';
			}
		}
		cout<<'\n';
	}
} 

