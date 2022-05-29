int sumK(Node *root,int k){
    p.clear();
    ans = 0;
    helper(root, k);
    return ans;
}

vector<int> p;
int ans = 0;
void helper(Node* root, int k){
    if(root == NULL)
        return;
    p.push_back(root->data);
    helper(root->left, k);
    helper(root->right, k);
    
    int sum = 0;
    for(int i=p.size()-1; i>=0; i--){
        sum += p[i];
        if(sum == k){
            ++ans;
            //for printing all paths 
            //print p[i...p.size()]
        }
    }

    p.pop_back();
}
