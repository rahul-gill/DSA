TreeNode* delete(TreeNode* root, int val){
	if(root == NULL) 
		return root;
	else if(val < root->val) 
		root->left = delete_node(root->left, val);
	else if(val > root->val) 
		root->right = delete_node(root->right, val);
	else if(root->left == NULL && root->right == NULL){ // Case 1
		delete root;
		root = NULL;
	}
	else if(root->left == NULL){ // Case 2
		node* temp = root;
		root= root->right;
		delete temp;
	}
	else if(root->right == NULL){ // Case 2
		node* temp = root;
		root = root->left;
		delete temp;
	}
	else{ // Case 3: 
		//place successor value at node and delete original successor node
		node* temp = root->right;
		while(temp->left != NULL) 
			temp = temp->left;
		root->val = temp->val;
		root->right = delete_node(root->right, temp->val);
	}
	return root;
}

