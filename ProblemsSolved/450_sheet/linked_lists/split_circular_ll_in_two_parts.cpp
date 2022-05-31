void splitList(Node *head, Node **head1_ref, Node **head2_ref){
    if(!head || !head->next)
        return;
        auto fast = head, slow = head;
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    };
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    if(fast->next == head)
        fast->next = *head2_ref;
    else if(fast->next->next == head)
        fast->next->next = *head2_ref;
}

