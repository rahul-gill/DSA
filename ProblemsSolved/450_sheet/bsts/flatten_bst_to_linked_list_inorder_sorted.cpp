using node_t = TreeNode<int>;

TreeNode<int>* flatten(TreeNode<int>* root, node_t*& prev_node, node_t*& head){
    if(!root)
        return NULL;
    flatten(root->left,prev_node,head);

    if(!prev_node){
        head = root;
    }
    else{
        prev_node->right = root;
        prev_node->left = NULL;
    }
    prev_node = root;
    flatten(root->right,prev_node,head);
    return head;
}

TreeNode<int>* flatten(TreeNode<int>* root){
    node_t* a = NULL,*b = NULL;
    node_t ans =  flatten(root, a, b);
    /* return ans; */
    //this below code for coding ninjas platform which had a bug that gives TLE if head from original BST is given
    if(!ans)
        return NULL;

    node_t* x = new node_t(ans->data);
    while(ans->right){
        x->right = new node_t(ans->right->data);
        x = x->right;
        ans = ans->right;
    }
    return x;
}



