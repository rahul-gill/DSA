#include<cp_debug.h>

bool cycle_check(const vector<vector<int>>& adj_list, vector<int>& visited, int node, int parent){
    visited[node] = 1;
    for(auto x: adj_list[node]){
        if(!visited[x]){
            if(cycle_check(adj_list,visited, x, node))
                return 1;
        }
        else if(x != parent)
            return 1;
    }
    return 0;
}
bool isGraphTree(int n, vector<vector<int>> &edgeList){
    vector<vector<int>> adj_list(n);
    for(auto x: edgeList){
        adj_list[x[0]].push_back(x[1]);
        adj_list[x[1]].push_back(x[0]);
    }

    vector<int> visited(n);

    bool cycle_check_res = cycle_check(adj_list, visited, 0, -1);
    if(cycle_check_res)
        return 0;

    for(auto x: visited)
        if(!x)
            return 0;
    return 1;
}

