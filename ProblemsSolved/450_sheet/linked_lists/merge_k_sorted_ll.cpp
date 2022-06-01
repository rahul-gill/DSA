Node* merge(Node* list1, Node* list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;

    Node* node = new Node(0);    
    auto h = node;
    while(list1 && list2){
        if(list1->data > list2->data){
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

Node * mergeKLists(Node *arr[], int K){
    if(!arr || !K)
        return NULL;

    auto node = arr[0];
    for(int i=1; i<K; ++i){
        node = merge(node, arr[i]);
    }
    return node;
}

