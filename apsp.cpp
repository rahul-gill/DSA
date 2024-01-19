#include<bits/stdc++.h>
using namespace std;

int AdjMat[400][400], V;
//V<400 for time constrain
void FloydWarshall(){
    //pre: AdjMat contains weight of edge (i,j) or INF if there is so such edge
    for (int k = 0; k < V; k++) // remember k->i->j
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}
/* Floyd Warshall DP
 * dp(i,j,-1) = weight of edge i->j      #base condition
 * dp(i,j,k)  = min[ dp(i,j,k-1),  dp(i,k,k-1) +  dp(k,j,k-1)  ] 
 */



/* for remembring path we use an 2D array
 * parent[i][j] is last vertex before j in path from i to j
 */
int p[400][400];
void FloydWarshall2(){
    for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
        p[i][j] = i;

    for (int k = 0; k < V; k++) 
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        if(AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]){
            AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
            p[i][j] = p[k][j];
        }
}
void printPath(int s, int d){
    if(s != d) printPath(s, p[s][d]);
    printf("->%d",d);
}
int main(){

}

/* 
 * ###other problems solvable with it
 * ---Transitive Closure(checking  if i is directly connected to j):
 *      AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
 * ---minimax:
 *     AdjMat[i][j] = min(  Adj[i][j] , max(AdjMat[i][k] , AdjMat[k][j])  ); 
 * ---Negative Cycles:
 *      set all diagonal entries INF. If at the end of algorithm any diagonal entry != INF => Negative cycle
 * ---diameter of graph(maximum of shortest path disatances between all vertices pairs):
 *      max entry in AdjMat after the algorithm run is the answer(ignore INF)
 * ---
 *      
*/