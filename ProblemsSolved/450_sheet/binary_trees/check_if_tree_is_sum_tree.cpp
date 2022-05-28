bool isSumTree(Node* root){
    bool ans = 1;
    helper(node, ans);
    return ans;
}


int helper(Node* node, bool &ans){
    if(node == NULL)
        return 0;
    auto ret = helper(node->left, ans) + helper(node->right, ans);
    auto ret2 = node->data;
    if((node->left || node->right) && node->data != ret)
        ans = false;
    return ret + ret2;
}

