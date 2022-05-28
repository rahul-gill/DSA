vector <int> postOrder(Node* root){
    if(root == NULL)
        return vector<int>();

    auto l =  postOrder(root->left);
    auto r =  postOrder(root->right);
    l.insert(l.end(), r.begin(), r.end());
    l.push_back(root->data);
    return l;
}


vector <int> postOrder(Node* root){
    vector<int> ans;
    stack<Node*> stk;
    Node* node = root;

    while(1){
        cnt++;
        if(node){
            stk.push(node);
            node = node->left;
        }
        else if(!stk.empty()){
            auto tmp = stk.top();
            if(tmp->right)
                node = tmp->right;
            else{
                stk.pop();
                ans.push_back(tmp->data);
                while(!stk.empty() && stk.top()->right == tmp){
                    tmp = stk.top(); stk.pop();
                    ans.push_back(tmp->data);
                }
            }
        }
        else
            break;
    }
    return ans;
}


