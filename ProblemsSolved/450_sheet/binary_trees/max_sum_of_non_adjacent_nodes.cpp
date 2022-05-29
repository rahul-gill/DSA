pair<int, int> helper(Node* root){
    if(!root)
        return {0,0};

    auto l = helper(root->left);
    auto r = helper(root->right);

    auto incr = root->data + l.second + r.second;
    auto excl = l.first + r.first;
    return {max(incr, excl), excl};
}

int getMaxSum(Node* root){
    return helper(root).first;
}
