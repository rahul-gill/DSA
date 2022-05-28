#include "bits/stdc++.h"

int checkMirrorTree(int n, int e, int A[], int B[]) {
    unordered_map<int, vector<int>> aj_list_a, aj_list_b;
    for(int i=0; i<2*e; i+=2){
        aj_list_a[A[i]].push_back(A[i+1]);
        aj_list_b[B[i]].push_back(B[i+1]);
    }
    if(aj_list_a.size() != aj_list_b.size())
        return 0;

    for(auto pr: aj_list_a){
        auto node = pr.first;
        auto edge_nodes = pr.second;
        auto edge_nodes_b = aj_list_b[node];
        if(edge_nodes.size() != edge_nodes_b.size())
            return 0;
        for(int i=0; i<edge_nodes; i++)
            if(edge_nodes[i] != edge_nodes_b[edge_nodes.size()-1-i])
                return 0;
    }
    return 1;
}