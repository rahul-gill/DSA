int printKthSmallest(struct Node* root, int k) {
    int cnt = 0;
    while(root){
        if(root->left){
            auto node = root->left;
            while(node->right &&  node->right != root)
                node = node->right;
            if(root == node->right){
                cnt++;
                if(cnt == k)
                    return root->data;
                node->right = NULL;
                root = root->right;
            }
            else{
                node->right = root;
                root = root->left;
            }
        }
        else{
            cnt++;
            if(cnt == k)
                return root->data;
            root = root->right;
        }
    }
    return -1;
}
