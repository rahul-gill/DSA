Node* deleteNode(Node* head, int key) {
    if(!head || head->data == key && head->next == head)
        return NULL;
    
    Node *node = head, *prev;
    //head case
    if(head->data == key){
        auto tmp = head;
        head = head->next;
        while(node->next != tmp)
            node = node->next;
        node->next = head;
        delete tmp;
        return head;
    }
    //middle case
    while(node->next != head){
        if(node->data == key){
            prev->next = node->next;
            delete node;
            return head;
        }
        prev = node;
        node = node->next;
    }
    //tail case
    if(node->data == key){
        prev->next = node->next;
        delete node;
    }
    return head;
}

