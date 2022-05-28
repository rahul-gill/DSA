vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    if(node == NULL)
        return ans;

    vector<vector<int>> levels;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int q_size = q.size();
        vector<int> level;
        while(q_size--){
            auto x = q.front(); q.pop();
            level.push_back(x->data);
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        levels.push_back(level);
    }
    for(int i=levels.size()-1; i>=0; i--){
        for(auto x: levels[i])
            ans.push_back(x);
    }
    return ans;

}
