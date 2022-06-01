Node* partition(Node* root, Node* end){
    Node* pivot = root, *node = root->next;

    while(node != end){
        if(node->data <= pivot->data)
            swap(node->data, pivot->data);
        node = node->next;
    }
    return pivot;
}

void quick_sort(Node* root, Node* end = NULL){
    if(!root || !root->next || root == end)
        return;

    Node* mid = partition(root, end);
    quick_sort(root, mid);
    quick_sort(mid->next, end);
}

void quickSort(Node** head){
    quick_sort(*head);
}
