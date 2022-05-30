tuple<int,int,int> helper(Node* root){
    if(!root)
        return make_tuple(INT_MIN, INT_MAX,0);

    auto l = helper(root->left);
    auto r = helper(root->right);

    if(root->data > get<0>(l) && root->data < get<1>(r))
        return make_tuple(max(get<0>(r),root->data), min(get<1>(l),root->data),get<2>(l) + get<2>(r)+1);

    return make_tuple(INT_MAX, INT_MIN, max(get<2>(l), get<2>(r)));
}

int largestBst(Node *root){
    return get<2>(helper(root));
}
