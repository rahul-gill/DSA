int getNthFromLast(Node *head, int n){
    auto nth = head;
    int i=1;
    while(nth && i<n){
        nth = nth->next;
        i++;
    }
    if(!nth)
        return -1;
    auto node = nth;
    nth = head;
    while(node->next){
        nth = nth->next;
        node = node->next;
    }
    return (nth) ? nth->data : -1;
}
