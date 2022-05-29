class Solution {
  public:
    map<string, int> mp;
    bool ans;

    string dfs(Node* root){
        if(root == NULL)
            return "";
        
        string tmp = to_string(root->data) + ' ' + dfs(root->left) + ' ' + dfs(root->right) + ' ';
        if(root->right || root->left)
            mp[tmp]++;

        if(mp[tmp] == 2)
            ans = 1;
        return tmp;
    }

    int dupSub(Node *root) {
        mp.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};
