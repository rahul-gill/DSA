#include<initializer_list>
#include<utility>
#include<iostream>
using namespace std;


struct node_t{
	int data;
	node_t* next;
};

pair<node_t*,node_t*> build_ll(initializer_list<int> list){
    if(list.size() == 0)
        return {NULL,NULL};
    node_t* root = new node_t;
    auto node = root;
    for(int item: list){
        node->data = item;
        node->next = new node_t;
        node = node->next;
    }
    return {root, node};
}

node_t* cycle_start_node(node_t* root){
	if(!root || !root->next || !root->next->next)
		return NULL;
	//already stepped one time ahead
	auto hare = root->next->next, tortoise = root->next;
	//only need to do not-null check for hare
	//because hare would reach null first in a linked list without cycle
	//and null will never be reached in a linked list with cycle
	while(hare != tortoise 
		  && hare->next 
		  && hare->next->next){
		hare = hare->next->next;
		tortoise = tortoise->next;
	}
	//hare and toroise will be same only when there is a cycle
	if(hare != tortoise)
		return NULL;
	//now the second part of algorithm, finding the start of cycle
	hare = root;
	while(hare != tortoise){
		hare = hare->next;
		tortoise = tortoise->next;
	}
	return hare;
}

bool test1(){
    auto [start, end] = build_ll({1,2,3,4,5,6,7,8,9,10});
    end->next = start->next->next->next;
    auto cycle_st = cycle_start_node(start);
    return cycle_st;
}
bool test2(){
    auto [start, end] = build_ll({1,2,3,4,5,6,7,8,9,10});
    auto cycle_st = cycle_start_node(start);
    return !cycle_st;
}

int main(){
    cout<<test1();
    cout<<test2();
}
