bool dfs(Node* root, int max_value = INT_MAX, int min_value = 1){
    if(!root)
        return 0;
    if(max_value == min_value)
        return 1;
    return dfs(root->left,root->data-1, min_value) or dfs(root->right, max_value, root->data+1);
}   


bool isDeadEnd(Node *root){
    return dfs(root);
}
