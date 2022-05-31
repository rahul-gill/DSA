void deleteNode(ListNode* node) {
    node->val = node->next->val;
    auto tmp = node->next;
    node->next = node->next->next;
    delete tmp;
}
