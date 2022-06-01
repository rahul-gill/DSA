//O(nlgk) solution
struct NodeComparator{
    bool operator ()(Node* a, Node* b){
        return a->data > b->data;
    }
};

Node *sortedDll(Node *head, int k){
    if(!head || !head->next || !k)
        return head;

    priority_queue<Node*, vector<Node*>, NodeComparator> pq;
    int i=k+1;
    auto node = head;
    while(i-- && node){
        pq.push(node);
        node = node->next; 
    }

    Node* new_head = NULL, *new_head_ref;
    while(!pq.empty()){
        auto top = pq.top();pq.pop();
        if(!new_head){
            new_head_ref = new_head = top;
            new_head->prev = NULL;
        }
        else{
            new_head->next = top;
            new_head->next->prev = new_head;
            new_head = new_head->next;
        }

        if(node){
            pq.push(node);
            node = node->next;
        }
    }
    new_head->next = NULL;
    return new_head_ref;
}
