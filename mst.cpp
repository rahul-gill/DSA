#include<bits/stdc++.h>
using namespace std;

//Minimum Spanning Tree Algorithms

//Kruskal's Algorithm
class unionFind {                             
private:
    vector<int> p, rank, setSize;                       
    int nSets;
public:
    unionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                    
        setSize.assign(N, 1);                  
        nSets = N;                          
    }

  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }

  int nDisjoint() { return nSets; }      
  int sizeOfSet(int i) { return setSize[find_set(i)]; } 

  void union_set(int i, int j) {
    if (same_set(i, j)) return;               
    int x = find_set(i), y = find_set(j);        
    if (rank[x] > rank[y]) swap(x, y);          
    p[x] = y;                                   
    if (rank[x] == rank[y]) ++rank[y];         
    setSize[y] += setSize[x];                   
    --nSets;          
  }
};

vector< pair<int,pair<int,int>> > edge_list; //entries of type ( weight, (vertexA, vertexB) )
int V = 5,E = 7;
void KruskalAlgorithm(){
    sort(edge_list.begin(), edge_list.end());
    int cost = 0;
    unionFind uf(V);
    for(int i=0; i<E; i++){
        auto edge = edge_list[i];
        if(!uf.same_set(edge.second.first, edge.second.second)){
            cost += edge.first;
            printf("(%d,%d)\n",edge.second.first, edge.second.second);
            uf.union_set(edge.second.first, edge.second.second);
        }
        if(uf.sizeOfSet(0) == V) break;
    }
    printf("cost = %d\n",cost);
}
//Prim's Algorithm
vector< vector<pair<int,int>> > adj_list(V);
vector<int> taken;
priority_queue<pair<int,int>> pq;
void process(int vertex){
    taken[vertex] = 1;
    for(auto x: adj_list[vertex])
        if(!taken[x.first]) pq.push(make_pair(-x.second,-x.first));
    
}
void primsAlgorithm(){
    process(0);
    int cost = 0;
    while(!pq.empty()){
        auto  front = pq.top(); pq.pop();
        int u = -front.second, w = -front.first;
        if(!taken[u]) 
            cost+=w, process(u);
    }
    printf("MST cost = %d\n",cost);
}

