#include<bits/stdc++.h>
using namespace std;

int n,m;
char grid[1010][1010];
bool visited[1010][1010];
int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};

int dfs(int x, int y){
    if(grid[x][y] == '#') return 1;
    visited[x][y] = 1;    
    for(int i=0; i<4; i++){
        if(x + dirx[i] < 0 || x+dirx[i] >= n) continue;   
        if(y + diry[i] < 0 || y+diry[i] >= m) continue;   
        if(!visited[x + dirx[i]][y + diry[i]])
            dfs(x + dirx[i], y + diry[i]);
    }
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            visited[i][j] = 0;
        }
    
    int rooms = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j]){
                int err = dfs(i,j);
                if(!err) rooms++;
            }
    cout<<rooms<<'\n';
    
}