template<typename F>
void inOrder(node_t* root, F&& f){
	if(root == NULL)
		return;
	inOrder(root->left, f);
	f(root);
	inOrder(root->right, f);
}



void populateNext(Node *root, Node* next = NULL, Node* prev = NULL){
    if(root == NULL)
        return;
    Node* prev = NULL;
    inOrder(
        root, 
        [&](Node* node){
            if(prev)
                prev->next = node;
            prev = node;
        }
    );
}


