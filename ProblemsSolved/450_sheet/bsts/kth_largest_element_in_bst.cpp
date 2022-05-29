int inorder(Node* root, int k, int& t){
    if(!root)
        return -1;

    int r = inorder(root->right, k,t );
    if(r != -1)
        return r;

    if(t == k)
        return root->data;
    else t++;
    
    return inorder(root->left, k,t);
}

int kthLargest(Node *root, int K){
    int t = 1;
    return inorder(root, K, t);
}
