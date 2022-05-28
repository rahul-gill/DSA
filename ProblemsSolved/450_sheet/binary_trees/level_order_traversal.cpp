#include<cp_debug.h>

vector<int> levelOrder(Node* node){
    vector<int> ans;
    if(node == NULL)
        return ans;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        auto x = q.front(); q.pop();
        ans.push_back(x->data);
        if(x->left)
            q.push(x->left);
        if(x->right)
            q.push(x->right);
    }
    return ans;
}
