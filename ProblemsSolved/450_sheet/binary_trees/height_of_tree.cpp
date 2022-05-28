int height(struct Node* node){
    if(node == NULL)
        return 0;

    queue<Node*> q;
    q.push(node);
    int levels = 0;
    while(!q.empty()){
        levels++;
        int q_size = q.size();
        while(q_size--){
            auto x = q.front(); q.pop();
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
    }
    return levels;

}
