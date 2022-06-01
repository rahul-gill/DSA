#include "linked_list.h"

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* next = head;
    while(next){
        auto tmp = next->next;
        next->next = prev;
        prev = next;
        next = tmp;
    }
    return prev;
}

Node *compute(Node *head){
    if(!head || !head->next)
        return head;
    head = reverseList(head);   
    
    auto prev = head, curr = head->next;
    int maxi = prev->data;
    while(curr){
        if(curr->data < maxi){
            auto tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete tmp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        maxi = max(maxi, prev->data);
    }
    return reverseList(head);
}
