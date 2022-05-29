template<typename F>
void inOrder(Node* root, F&& f){
	if(root == NULL)
		return;
	inOrder(root->left, f);
	f(root);
	inOrder(root->right, f);
}


Node *binaryTreeToBST (Node *root){
    vector<int> trv;
    inOrder(
        root,
        [&](Node* n){
            trv.push_back(n->data);
        }
    );
    sort(trv.begin(), trv.end());
    int i=0;
    inOrder(
        root,
        [&](Node* n){
            n->data = trv[i++];
        }
    );
    return root;
}
