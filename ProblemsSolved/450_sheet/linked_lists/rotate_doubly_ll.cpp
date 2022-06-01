Node *rotateDLL(Node *start,int p){
    if(!start || !start->next)
        return start;

    int sz = 0;
    auto node = start, last = start;
    while(node){
        last = node;
        node = node->next;
        ++sz;
    }

    p = p % sz;
    int i = 1;
    node = start;
    while(i++ < p)
        node = node->next;

    auto head_new = node->next;
    head_new->prev = NULL;
    node->next = NULL;
    start->prev = last;
    last->next = start;
    return head_new;
}
