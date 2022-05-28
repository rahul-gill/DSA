Node* lca(Node* root, int a, int b){
    if(root == NULL || root->data == a || root->data == b)
        return root;
    auto l = lca(root->left, a, b);
    auto r = lca(root->right, a, b);

    if(!l)
        return r;
    if(!r)
        return l;
    return root;
}

int dist(Node* root, int a, int prev = 0){
    if(root == NULL)
        return -1;
    if(root->data == a)
        return prev;
    int l = dist(root->left,a,prev+1);
    if(l != -1)
        return l;
    return  dist(root->right,a,prev+1);
}
int findDist(Node* root, int a, int b) {
    if(root == NULL)
        return 0;
    auto lca_node = lca(root, a,b);
    return dist(lca_node, a) + dist(lca_node, b);
}
