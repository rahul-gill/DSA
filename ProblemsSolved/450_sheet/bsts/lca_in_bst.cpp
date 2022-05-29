Node* LCA(Node *root, int n1, int n2){
    while(1){
        if(!root)
            return 0;
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
}


