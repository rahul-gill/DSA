void flatten(Node *root){
    
    while(root){
        if(root->left){
            auto rightmost = root->left;
            while(rightmost->right)
                rightmost = rightmost->right;
            
            rightmost->right = root->right;
            auto tmp = root->left;
            root->right = root->left;
            root->left = NULL;
            root = tmp;
        }
        else{
            root = root->right;
        }
    }
}
