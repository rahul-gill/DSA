Node * removeDuplicates( Node *head){
    if(!head)
        return head;
    auto node = head;
    map<int, Node*> mp;

    Node* prev;
    while(head){
        if(mp.find(head->data) == mp.end()){
            mp[head->data] = head;
            prev = head;
            head = head->next;
        }
        else{
            auto tmp = head;
            prev->next = head->next;
            head = head->next;
            delete tmp;
        }
    }
    return node;
}
