bool search(struct Node* root, int x) {
    if(root == NULL)
        return 0;
    if(root->data == x)
        return 1;
    else if(root->data > x)
        return search(root->left, x);
    else
        return search(root->right, x); 
}

Node* search(struct Node* root, int x){
    if(root == NULL)
        return 0;
    while(1){
        if(!root)
            return 0;
        else if(root->data == x)
            return root;
        else if(root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}
