//into new list
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    
    ListNode* node = new ListNode(0);    
    auto h = node;
    while(list1 && list2){
        if(list1->val > list2->val){
            node->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        else{
            node->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        node = node->next;
    }
    while(list1){
        node->next = new ListNode(list1->val);
        list1 = list1->next;
        node = node->next;
    }
    while(list2){
        node->next = new ListNode(list2->val);
        node = node->next;
        list2 = list2->next;
    }
    return h->next;
}


//inplace
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;

    ListNode* node = new ListNode(0);    
    auto h = node;
    while(list1 && list2){
        if(list1->val > list2->val){
            node->next = list2;
            list2 = list2->next;
        }
        else{
            node->next = list1;
            list1 = list1->next;
        }
        node = node->next;
    }
    while(list1){
        node->next = list1;
        list1 = list1->next;
        node = node->next;
    }
    while(list2){
        node->next = list2;
        node = node->next;
        list2 = list2->next;
    }
    return h->next;
}
