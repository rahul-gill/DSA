vector <int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    ans.push_back(root->data);
    auto l = preorder(root->left);
    auto r = preorder(root->right);
    ans.insert(ans.end(), l.begin(), l.end());
    ans.insert(ans.end(), r.begin(), r.end());
    return ans;
}


vector <int> preorder2(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty()){
        auto node = stk.top(); stk.pop();
        ans.push_back(node->data);
        
        if(node->right)
            stk.push(node->right);
        if(node->left)
            stk.push(node->left);
    }
}
