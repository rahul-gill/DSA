int ans = -1;
node_t* helper(node_t *root, int targetNodeVal, int& k) {
    if(root == NULL)
        return NULL;

    node_t* rv = NULL;
    if(root->data == targetNodeVal
        || (rv = helper(root->left, targetNodeVal, k))
        || (rv = helper(root->right, targetNodeVal, k))){
        if(k == 0){
            ans = root->data;
            return NULL;
        }
        k--;
        return rv ? rv : root;
    }
    
    return NULL;
}


int findKthAncestor(node_t *root, int targetNodeVal, int& k) {
    ans = -1;
    helper(root, targetNodeVal, k);
    return ans;
}

