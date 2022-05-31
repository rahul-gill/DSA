void removeLoop(Node* head){
    if(!head || !head->next || !head->next->next)
        return;

    Node* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast)
        return;

    fast = head;
    if(slow==fast) while(slow->next != fast)
        slow = slow->next;
    else while(slow->next != fast->next){
        debug(slow->data,fast->data);
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
