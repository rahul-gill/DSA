Node* helper(int in[], int pre[], unordered_map<int,int>& node_idx, int n, int in_st, int in_end, int pre_st, int pre_end){
    if(in_st >= in_end)
        return NULL;

    Node* root = new Node(pre[pre_st]);
    if(in_st + 1 == in_end)
        return root;

    int root_in_idx = node_idx[root->data];
    int left_size = root_in_idx - in_st;
    root->left = helper(in, pre, node_idx, n,
        in_st, root_in_idx,
        pre_st + 1, (pre_st + 1) + left_size
    );
    root->right = helper(in, pre, node_idx, n,
        root_in_idx+1, in_end,
        (pre_st + 1) + left_size, pre_end
    );
    
    return root;
}

Node* buildTree(int in[],int pre[], int n){
    unordered_map<int,int> node_idx;
    for(int i=0; i<n; i++)
        node_idx[in[i]] = i;
    return helper(in, pre, node_idx, n, 0, n, 0, n);
}

