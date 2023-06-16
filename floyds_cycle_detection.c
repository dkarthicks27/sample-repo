bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *slow = head;
    SinglyLinkedListNode *fast = head;
    
    if(head == NULL || head->next == NULL){
        return 0;
    }
    
    slow = slow->next;
    fast = fast->next->next;
    
    if(slow==fast)
        return 1;
        
        
    while(fast != NULL && fast->next != NULL){
        if(slow==fast)
            return 1;
        
        slow = slow ->next;
        fast = fast->next->next;
    }
    
    return 0;
}
