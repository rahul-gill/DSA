bool isCircular(struct Node *head){
    if(!head)
    return 1;
    struct Node* node = head;
    while(node){
        if(node->next == head)
        return 1;
        node = node->next;
    }
    return 0;
}
