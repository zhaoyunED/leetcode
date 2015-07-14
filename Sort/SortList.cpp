Sort a linked list in O(n log n) time using constant space complexity.


//merge sort的利用
// 加强 链表的使用
ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) {
            return head;
        }
    	ListNode *middle = getMiddle(head);
    	ListNode *next   = middle->next;
    	middle->next = NULL;
    	return merge(sortList(head),sortList(next));
    }
    
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* first = head;
        ListNode* second = head;
        
        while(first && second->next && second->next->next )
        {
            first = first->next;
            second = second->next->next;
        }
        
        return first;
    }
    
    
    ListNode* merge(ListNode* first,ListNode* second)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curry = dummy;
        
        while(first && second)
        {
            if(first->val < second->val)
            {
                curry->next = first;
                first = first->next;
            }else{
                curry->next = second;
                second = second->next;
            }
            curry = curry->next;
        }
        
        
        if(first)
            curry->next = first;
        else
            curry->next = second;
        
        return dummy->next;
    }