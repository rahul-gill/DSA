void toSumTree(Node *node){
    helper(node);
}


int helper(Node* node){
    if(node == NULL)
        return 0;
    auto ret = helper(node->left) + helper(node->right);
    auto ret2 = node->data;
    node->data = ret;
    return ret + ret2;
}
