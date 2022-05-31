Node* reverseDLL(Node * head){
    if(!head)
        return head;

    auto node = head;
    while(1){
        swap(node->prev, node->next);
        if(node->prev)
            node = node->prev;
        else
            return node;
    }
    return 0;
}

