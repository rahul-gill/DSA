void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    pre = NULL;
    suc = NULL;
    if(!root)
        return;

}
void helper(Node* root, Node*& pre, Node*& suc, int key){
    if(!root)
        return;
    if(root->key > key){
        if(!suc || suc->key > root->key)
            suc= root;
    }
    else if(root->key < key){
        if(!pre || pre->key < root->key)
            pre = root;
    }
    helper(root->left, pre, suc, key);
    helper(root->right, pre, suc, key);
}
