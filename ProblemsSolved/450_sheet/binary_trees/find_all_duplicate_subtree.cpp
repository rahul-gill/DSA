class Solution {
  public:
    map<string, int> mp;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root){
        if(root == NULL)
            return "";
        
        string tmp = to_string(root->val) + ' ' + dfs(root->left) + ' ' + dfs(root->right) + ' ';
        mp[tmp]++;

        if(mp[tmp] == 2)
            ans.push_back(root);
        return tmp;
    }

    vector<TreeNode*> dupSub(TreeNode *root) {
        mp.clear();
        ans.clear();
        dfs(root);
        return ans;
    }
};

