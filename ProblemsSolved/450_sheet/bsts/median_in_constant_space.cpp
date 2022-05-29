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


float findMedian(struct Node *root){
    vector<int> tr;
    morris(root, [&](Node* x){
        tr.push_back(x->data);
    });
    int n = tr.size();
    if(n & 1)
        return tr[n/2];
    return (tr[n/2 -1] + tr[n/2]) / 2.0;

}

//constant  space solution:
float findMedian2(Node* root){
    int total = 0;
    morris(root, [&](Node* x){
        ++total;
    });
    int ans, ans2;
    morris(root, [&](Node* x){
        if(i == total / 2)
            ans = x->data;
        if(i == total / 2 -1)
            ans2 = x->data;
        i++;
    });
    if(total & 1)
        return ans;
    else
        return (ans + ans2) / 2.0;
}
