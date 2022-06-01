#include "linked_list.h"

Node *copyList(Node *head){
    if(!head)
        return NULL;
    //copy nodes inbetween current list nodes
    auto node = head;
    while(node){
        auto tmp = node->next;
        node->next = new Node(node->data);
        node->next->next = tmp;
        node = tmp;
    }
    //fill up arb pointers
    node = head;
    while(node){
        if(node->next)
            node->next->arb = (node->arb) ? (node->arb->next) : NULL;
        node = node->next->next;
    }
    //seperate out new list
    Node* new_head = NULL, *new_head_ref;
    node = head;
    while(node){
        auto tmp = node->next;
        node->next = tmp->next;
        if(!new_head)
            new_head = new_head_ref = tmp;
        else{
            new_head->next = tmp;
            new_head = new_head->next;
        }
        node = node->next;
    }
    return new_head_ref;
}
