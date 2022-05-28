Node* lca(Node* root ,int n1 ,int n2 ){
    if(root == NULL || root->data == n1 || root->data == n2)
        return root;

    auto l = lca(root->left, n1, n2);
    auto r = lca(root->right, n1, n2);

    if(!l)
        return r;
    if(!r)
        return l;
    return root;
}
