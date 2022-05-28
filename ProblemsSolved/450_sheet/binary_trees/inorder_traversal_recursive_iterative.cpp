vector<int> inOrder(Node* root) {
    if(root == NULL)
        return vector<int>();
    auto l = inOrder(root->left);
    auto r = inOrder(root->right);
    l.push_back(root->data);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}        

template<typename Functor>
void inOrder2(Node* root, Fuctor&& f){
    stack<Node*> stk;
    Node* node = root;
    while(1){
        if(node){
            stk.push(node);
            node = node->left;
        }
        else if(!stk.empty()){
            node = stk.top(); stk.pop();
            f(node->data);
            node = node->right;
        }
        else
            break;
    }
}
