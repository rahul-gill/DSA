using node_t = Node;
template<typename Functor>
void morris(node_t* root, Functor f){
	while(root != NULL){
		if(root->left != NULL){
			auto rightmost = root->left;
			while(rightmost->right != NULL && rightmost->right != root)
				rightmost = rightmost->right;
			if(rightmost->right == root){
				rightmost->right = NULL;
				f(root); //x
				root = root->right;
			}
			else{
				rightmost->right = root;
				//y
				root = root->left;
			}
		}
		else{
			f(root);
			root = root->right;
		}
	}
}

int getCount(Node *root, int l, int h){
    int cnt = 0;
    morris(root,[&](Node* node){
        if(node->data >= l && node->data <= h)
            ++cnt;
    });
    return cnt;
}
