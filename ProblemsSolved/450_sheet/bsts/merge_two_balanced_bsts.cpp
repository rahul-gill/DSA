using node_t =  TreeNode<int>;
//converting to linked list: preorder
TreeNode<int>* flatten(TreeNode<int>* root, node_t*& prev_node, node_t*& head){
    if(!root)
        return NULL;
    flatten(root->left,prev_node,head);

    if(!prev_node){
        head = root;
    }
    else{
        prev_node->right = root;
        prev_node->left = NULL;
    }
    prev_node = root;
    flatten(root->right,prev_node,head);
    return head;
}

TreeNode<int>* toLL(TreeNode<int>* root){
    node_t* a = NULL,*b = NULL;
    node_t ans =  flatten(root, a, b);
    return ans;
}

//bst building from preorder
node_t* helper(const vector<int>& preorder, int st, int end){
    if(st>=end || st<0)
        return NULL;
    node_T* root = new node_t(preorder[st]);
    
    int right_st = lower_bound(preorder.begin()+st+1, preorder.begin()+end, preorder[st]) - preorder.begin();
    if(right_st == end)
        root->right = NULL;
    else
        root->right = helper(preorder, right_st, end);
    root->left = helper(preorder, st+1, right_st);
    return root;
}

node_t* bstFromPreorder(const vector<int>& preorder) {
    return helper(preorder, 0, preorder.size());
}

//final merge method
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    if(!root1 && !root2)
        return NULL;
    if(!root1)
        return root2;
    if(!root2)
        return root1;

    auto l1 = toLL(root1);
    auto l2 = toLL(root2);
    vector<int> l;
    while(l1 && l2){
        if(l1->data < l2->data){
            l.push_back(l1->data);
            l1 = l1->right;
        }
        else{
            l.push_back(l2->data);
            l2 = l2->right;
        }
    }
    while(l1){
        l.push_back(l1->data);
        l1 = l1->right;
    }
    while(l2){
        l.push_back(l2->data);
        l2 = l2->right;
    }
    return bstFromPreorder(l);
}
