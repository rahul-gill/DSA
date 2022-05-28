int diameter(Node* root){
    int maxi = 0;
    diameter_h(root, maxi);
    return maxi;
}

int diameter_h(Node* root, int& maxi) {
    if(root == NULL)
        return 0;
    int l = diameter_h(root->left,maxi);
    int r = diameter_h(root->right,maxi);
    maxi = max(maxi, 1 + r + l);
    return 1 + max(l,r);
}
