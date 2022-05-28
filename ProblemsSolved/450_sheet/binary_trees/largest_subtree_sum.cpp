int helper(TreeNode<int> *root, int& maxi) {
    if(root == NULL)
        return 0;

    int sum = root->data + helper(root->left, maxi) + helper(root->right, maxi);
    maxi = max(maxi, sum);
    return sum;
}
int largestSubtreeSum(TreeNode<int>* root){
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
}
