Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


//有pre指针的
ListNode *deleteDuplicates(ListNode *head) 
{
        if(head==NULL || head->next==NULL) return head;  
    ListNode* c = head->next;  
    ListNode* p = head;  
      
    while(c!=NULL) // We assume that there is no loop in the list.  
    {  
        ListNode* n = c->next;  
          
        if(p->val == c->val)  
        {  
            p->next = n;  
            delete c;  
            c = n;  
        }  
        else  
        {  
            p = c;  
            c = n;              
        }      
    }  
    return head;  
}

//	双重指针
ListNode* deleteDuplicates(ListNode* head) 
{
        if(head ==NULL || head->next ==NULL)
            return head;
		ListNode** pre =&head;

        while(*pre && (*pre)->next)
        {
            int pvalue =(*pre)->val;
            
			if((*pre)->next->val == pvalue)
            {
                ListNode *temp = *pre;
                *pre = (*pre)->next;
                delete temp;
            }else{
				pre =&(*pre)->next;
			}
        }
        
        return head;
}

//其实也可以不用双重指针 并没有考虑到delete的
ListNode *deleteDuplicates(ListNode *head) 
{
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
 }