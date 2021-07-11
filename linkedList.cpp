#include<bits/stdc++.h>
using namespace std;

typedef struct list
{
    int item;
    struct list* next;
}list;

list *seach_list(list *l, int x){ 
    while(l != NULL && l->data != x) l = l->next;    
    return l;
}

void insert_list(list **l, int x)
{
    list *p;
    p = malloc( sizeof(list) );
    p->item = x;
    p->next = *l;
    list *pred = predecessor_list(*l,(*l)->data);
    pred->next = p;
}

list *predecessor_list(list *l, int x)
{
    while(l!=NULL && l->next!=NULL &&  (l->next)->item != x)
        l = l->next;
    if(l==NULL || l->next == NULL) return NULL;
    else return list;
}
void delete_list(list **l, int x)
{
    list *p = search_list(*l,x);
    if (p != NULL) {
        list *pred = predecessor_list(*l,x);
        if (pred == NULL) /* handles 'not found' and 'first element' cases */
            *l = p->next;
        else
            pred->next = p->next;
            free(p);
    }
}

