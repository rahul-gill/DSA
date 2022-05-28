//mirror of tree or invert the binary tree

TreeNode* invertTree(TreeNode* root) {
    if(root!=NULL){
        auto tmp = root->left;
        root->left= root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}
