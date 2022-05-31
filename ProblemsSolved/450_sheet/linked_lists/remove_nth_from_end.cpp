node_t* removeNthFromEnd(node_t* head, int n){
    auto dummy = new node_t(0);
    dummy->next = head;
    node_t *fast = dummy, *slow = dummy;

    for(int i=0; i<n; ++i)
        fast = fast->next;
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    if(slow == dummy){
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
    else{
        auto tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
    }
    return head;
}

