Node *removeDuplicates(Node *head){
    if(!head)
        return head;
    auto node = head;
    auto prev = head;
    while(head->next){
        head = head->next;
        if(prev->data == head->data){
            prev->next = head->next;
            delete head;
        }
        else
            prev = head;
    }
    return node;
}

