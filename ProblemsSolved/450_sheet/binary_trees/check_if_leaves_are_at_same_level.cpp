bool is_leaf(Node* node){
    return !node->left && !node->right;
}
bool check(Node *root){
    int level = 0;
    helper(root, 1, level);
}

bool helper(Node* root, int curr_level, int &level){
    if(root == NULL)
        return 1;

    if(is_leaf(root)){
        if(!level)
            level = curr_level;
        return level == curr_level;
    }
    else
        return helper(root->left, curr_level + 1, level) && helper(root->right, curr_level+1, level);
}
