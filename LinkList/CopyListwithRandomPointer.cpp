A linked list is given such that each node contains an additional random pointer which could point 
to any node in the list or null.

Return a deep copy of the list.



RandomListNode *copyRandomList(RandomListNode *head)
{
        if(head == NULL) return NULL;
    RandomListNode *p = head;
    do {
        RandomListNode *q = p->next;
        p->next = new RandomListNode(p->label);
        p->next->next = q;
        p = q;
    } while(p != NULL);
    p = head;
    do {
        p->next->random = (p->random == NULL) ? NULL : p->random->next;
        p = p->next->next;
    } while(p != NULL);
    p = head;
    RandomListNode *r = head->next;
    for(RandomListNode *q = r;;) {
        p->next = q->next;
        p = p->next;
        if(p == NULL) break;
        q->next = p->next;
        q = q->next;
    }
    return r;
}


RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> relation;  
          
        RandomListNode* copiedHead= NULL;  
        RandomListNode* copiedPtr=NULL;  
        RandomListNode* ptr = head;  
          
        while(ptr!=NULL)  
        {  
            RandomListNode* new_node = new RandomListNode(ptr->label);  
            relation.insert(pair<RandomListNode*, RandomListNode*>(ptr, new_node));  
            if(copiedHead==NULL)  
            {  
                copiedHead = new_node;  
                copiedPtr = new_node;  
            }  
            else  
            {  
                copiedPtr->next = new_node;  
                copiedPtr=copiedPtr->next;  
            }  
            copiedPtr->random = ptr->random;  
            ptr=ptr->next;  
        }  
          
        ptr=head;  
        copiedPtr = copiedHead;  
        while(ptr!=NULL)  
        {  
            if(ptr->random!=NULL)  
            {  
                copiedPtr->random = relation[ptr->random];  
            }  
            copiedPtr=copiedPtr->next;  
            ptr=ptr->next;  
        }  
        return copiedHead;  
    
    }