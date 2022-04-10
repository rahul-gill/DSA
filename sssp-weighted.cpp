#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define INF 1000000000

vector<vector<  pair<int,int>  >> adj_list={
    {ii(1,4), ii(7,8)},
    {ii(0,4), ii(7,11), ii(2,8)},
    {ii(1,8), ii(8,2), ii(5,4), ii(3,7)},
    {ii(2,7), ii(5,14), ii(4,9)},
    {ii(3,9), ii(5,10)},
    {ii(2,4), ii(3,14), ii(4,10), ii(6,2)},
    {ii(5,2), ii(7,1), ii(8,6)},
    {ii(0,8), ii(1,11), ii(6,1), ii(8,7)},
    {ii(2,2), ii(6,6), ii(7,7)},
};
int V = 9;

void Dijkstra(int src)
{   //Dijlstra Set Based Implemnetation
    set< pair<int, int> > setds;
    vector<int> dist(V, INF);
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    while (!setds.empty()){
        auto u = (setds.begin())->second;
        setds.erase(setds.begin());
        int k = 0;
        for (auto i: adj_list[u])
        {   ;
            int v = i.first, weight = i.second;
            if (dist[v] > dist[u] + weight){
                //this if below can be ommited(lazy deletion), this also creates problem
                //in negative weight graphs

                //if (dist[v] != INF)
                    //setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    cout<<endl;
}
int main(){
    Dijkstra(0);

    //Dijkstra fails with graphs with negative weight cycles

    //Priority queue based implementation
    int s = 0;//source
    priority_queue<ii,vector<ii>,  greater<ii>> pq;
    pq.push(make_pair(0,s));
    vector<int> dist(V,INF);
    dist[s] = 0;
    //Lazy deletion, will cause duplicate items in priority queue
    //other duplicates will have higher distances, so will be ignored   
    while(!pq.empty()){
        auto front = pq.top(); pq.pop();
        int d = front.first;
        int u = front.second;

        for(auto x:adj_list[u])
            if(dist[u] + x.second < dist[x.first]){
                dist[x.first] =dist[u] + x.second;
                pq.push(make_pair(dist[x.first],x.first));
            }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
