ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> a_nodes;
    
    auto node = headA;
    while(node){
        a_nodes.insert(node);
        node = node->next;
    }

    node = headB;
    while(node){
        if(a_nodes.find(node) != a_nodes.end())
            return node;
        node = node->next;
    }
    return NULL;
}

//or find length l1 and l2 of lists, move head of longer by (l1-l2) and then traverse then together until same node is found


//or do this
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)
        return NULL;

    auto a = headA, b = headB:
    while(a != b){
        a = (a) ? a->next : headB;
        b = (b) ? b->next : headA;
        if(!a && !b)
            return NULL;
    }
}
