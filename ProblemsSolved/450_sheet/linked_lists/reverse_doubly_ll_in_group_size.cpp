pair<Node*,bool> kth_node(Node* groupStart, int k){
    int num = 1;
    Node* tmp;
    while(groupStart){
        tmp = groupStart;
        if(num == k)
            return {groupStart, 0};
        groupStart = groupStart->next;
        num++;
    }
    return {tmp, 1};
}

Node* reverseDLLInGroups(Node* head, int k){
    if(!head)
        return head;

    auto dummy = new Node(0);
    dummy->next = head;

    auto gpPrev = dummy;
    while(1){
        auto gpStart = gpPrev->next;
        if(!gpStart)
            break;
        auto tmp = kth_node(gpStart,k);
        auto kth = tmp.first;

        auto gpNext = kth->next;
        //reversing
        gpStart->prev = gpNext;
        auto node = gpStart;
        while(node != gpNext){
            swap(node->prev,node->next);
            node = node->prev;
        }
        //ptrs
        if(gpNext)
            gpNext->prev = gpStart;
        gpPrev->next = kth;
        gpPrev = gpStart; 
        if(tmp.second)
            break;
    }
    return dummy->next;
}
