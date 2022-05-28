#include<cp_debug.h>

Node *head = NULL, *previ = NULL;

void helper(Node* root){
    if(root == NULL)
        return;

    helper(root->left);
    if(previ == NULL){
        head = root;
    }
    else{
        previ->right = root;
        root->left = previ;
    }
    previ = root;
    helper(root->right);
}

Node* bToDLL(Node* root){
    helper(root);
    return head;
}
