TreeNode* helper(const vector<int>& preorder, int st, int end){
    if(st>=end || st<0)
        return NULL;
    TreeNode* root = new TreeNode(preorder[st]);
    
    int right_st = lower_bound(preorder.begin()+st+1, preorder.begin()+end, preorder[st]) - preorder.begin();
    if(right_st == end)
        root->right = NULL;
    else
        root->right = helper(preorder, right_st, end);
    root->left = helper(preorder, st+1, right_st);
    return root;
}

TreeNode* bstFromPreorder(const vector<int>& preorder) {
    return helper(preorder, 0, preorder.size());
}
