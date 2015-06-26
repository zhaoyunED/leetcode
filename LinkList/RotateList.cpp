Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


//·½·¨1 make a circle
ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL||k==0) return head;
        
        ListNode* node = head;
        int size =1;
        while(node->next != NULL)
        {
            size++;
            node = node->next;
        }
        
        node->next = head; //make circle
        
        k = k%size;
        
        int num = size -k;
        
        while(num--)
        {
            node = node ->next;
        }
        
        ListNode* first = node->next;
        node->next=NULL;

        return first;
    }



	ListNode *rotateRight(ListNode *head, int k) {
        if(k==0 || head ==NULL || head->next ==NULL)
            return head;
            
        ListNode* ptr =head;
        ListNode* tail =head;
        int length =0;
        
        while(ptr!=NULL)
        {
            tail = ptr;
            ptr =ptr->next;
            length++;
        }
        
        k= k%length;
        
        ptr=head;
        for (int i = 0; i < length - k - 1; i++) {  
            ptr = ptr-> next;  
        } 
        
        tail->next = head;  
        head = ptr->next;  
        ptr->next = NULL;  
          
        return head;  
    }