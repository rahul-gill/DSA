LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
    if(!head || !head->next)
        return head;

    auto before_last = head, last = head->next;
    while(last->next){
        before_last = before_last->next;
        last = last->next;
    }

    last->next = head;
    before_last->next = NULL;
    return last;
}

