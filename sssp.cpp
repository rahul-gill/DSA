#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list={
    {1,5},
    {0,4},
    {4},
    {5},
    {1,2,6,7},
    {0,3},
    {4,8},
    {4,8},
    {6,7},
};
int V = 9;
vector<int> parent(V,-1);

void bfs(int v){
    vector<int> visited(V,0);
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto x:adj_list[u])
            if(!visited[x]){
                parent[x] = u;
                q.push(x);
                visited[x] = 1;
            }
    }
}
void printUndirectedPath(int u, int v){
    if(u == v) { printf("%d", v); return; }
    printUndirectedPath(parent[u],v);
    printf("->%d",u);
}

int main(){
    int dest = 0;
    bfs(dest);
    printUndirectedPath(6,dest);
}
