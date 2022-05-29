using data_t = int;
using node_t = Node;
node_t* insert(node_t* root,data_t data){
    if(root == NULL){
        root = new node_t(data);
        return root;
    }
    auto node = root;
	while(1){
        if(node->data > data){
            if(node->left)
			    node = node->left;
            else{
                node->left = new node_t(data);
                break;
            }
        }
        else if(node->data < data){
            bool s = node->data == 4;
            if(node->right)
                node = node->right;
            else{
                node->right = new node_t(data);
                break;
            }
        }
        else
            break;
	}
    return root;
}


