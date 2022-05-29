using node_t = Node;
using data_t =int;
template<typename Functor>
void inOrder(node_t* root,Functor&& f){
	if(root == NULL)
		return;
	inOrder(root->left, f);
	f(root->data);
	inOrder(root->right, f);
}
bool isValidBST(node_t* root) {
	long long prev = LLONG_MIN;
	ans = 1;
    inOrder(
        root, 
        [&](data_t data){ 
            if(data <= prev)
            ans = 0;
            prev = data;
        }
    );
    return ans;
}
