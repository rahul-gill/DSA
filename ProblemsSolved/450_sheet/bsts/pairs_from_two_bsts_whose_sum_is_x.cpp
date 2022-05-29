using node_t = Node;
template<typename F>
void inOrder(node_t* root, F&& f){
	if(root == NULL)
		return;
	inOrder(root->left, f);
	f(root->data);
	inOrder(root->right, f);
}

int countPairs(Node* root1, Node* root2, int x){
    vector<int> a, b;
    inOrder(root1, [&](int d){ a.push_back(d); });
    inOrder(root2, [&](int d){ b.push_back(d); });
    
    unordered_set<int> a_set;
    for(int i: a)
        a_set.insert(i);

    int cnt = 0;
    for(int i: b)
        if(a_set.find(x-i) != a_set.end())
            cnt++;
    return cnt;
}
