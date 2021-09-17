#include<bits/stdc++.h>
using namespace std;

class UnionFind {                              
private:
    vector<int> p, rank, setSize;                       
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           
        //setSize.assign(N, 1);                        // setSize extension
        //numSets = N;                                 // numSets extension
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    //int numDisjointSets() { return numSets; }      //  numSets extension
    //int sizeOfSet(int i) { return setSize[findSet(i)]; } // setSize extension

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 
        int x = findSet(i), y = findSet(j);         
        if (rank[x] > rank[y]) swap(x, y);           
        p[x] = y;                                   
        if (rank[x] == rank[y]) ++rank[y];          
        //setSize[y] += setSize[x];  //setSize extension                 
        //--numSets;                 //numSets extension           
    }
};
int main(){
	cin.tie(0);
    int n,m1,m2;
	cin>>n>>m1>>m2;
	UnionFind mocha(n), dianna(n);
	for(int i=0; i<m1; i++){
		int a,b;
		cin>>(a)>>(b);
		a--,b--;
		mocha.unionSet(a,b);
	}
	for(int i=0; i<m2; i++){
		int a,b;
		cin>>(a)>>(b);
		a--,b--;
		dianna.unionSet(a,b);
	}
	vector<pair<int,int>> common_addable_edges;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			if(!mocha.isSameSet(i,j) && !dianna.isSameSet(i,j)){
				mocha.unionSet(i,j);
				dianna.unionSet(i,j);
				common_addable_edges.push_back({i,j});
			}
		}
	int size_val = common_addable_edges.size();
	cout<<size_val<<'\n';
	if(size_val != 0) for(auto x:common_addable_edges){
		cout<<x.first+1<<' '<<x.second+1<<'\n';
	}
}
