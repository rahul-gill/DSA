void inorder(Node* root, vector<int>& t){
    if(!root)
        return;
    inorder(root->left,t);
    t.push_back(root->data);
    inorder(root->right,t);
}

Node* helper(vector<int> t, int st, int end){
    if(st>=end || end>t.size() || st<0)
        return NULL;

    Node* root = new Node(t[st + (end-st)/2]);
    root->left = helper(t, st, st +  (end-st)/2);
    root->right = helper(t, st + (end-st)/2 + 1, end);

    return root;
}

Node* buildBalancedTree(Node* root){
    vector<int> t;
    inorder(root,t);
    return helper(t,0,t.size());
}
