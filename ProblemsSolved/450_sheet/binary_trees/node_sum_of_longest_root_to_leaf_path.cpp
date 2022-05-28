pair<int,int> sumOfLongRootToLeafPathHelper(Node *root, int level = 0, int sum = 0){
    if(root == NULL)
        return make_pair(level, 0);

    auto l = sumOfLongRootToLeafPathHelper(root->left, level+1, sum + root->data);
    auto r = sumOfLongRootToLeafPathHelper(root->right, level+1, sum + root->data);
    if(l.first > r.first)
        return make_pair(l.first, l.second + root->data);
    else if(l.first < r.first)
        return make_pair(r.first, r.second + root->data);
    else if(l.second > r.second)
        return make_pair(l.first, l.second + root->data);
    else
        return make_pair(r.first, r.second + root->data);
}

int sumOfLongRootToLeafPath(Node *root) {
    return sumOfLongRootToLeafPathHelper(root).second;
}