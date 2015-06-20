Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.


//普通方法 
ListNode *removeNthFromEnd(ListNode *head, int n)
{
         if (head == NULL)
            return NULL;
            
        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 0; i < n - 1; i++)  //先让q指针先走n步
            q = q->next;
            
        while(q->next)
        {
            pPre = p;
            p = p->next;
            q = q->next;
        }
        
        if (pPre == NULL)
        {
            head = p->next;
            delete p;
        }
        else
        {
            pPre->next = p->next;
            delete p;
        }
        
        return head;
}


//Linus Torvalds 的双重指针方法

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	   ListNode* fast = head;
        
        for(int i=0;i<n;i++)
            fast = fast->next;
        
        ListNode** pre =&head;
        
        while(fast)
        {
            fast = fast->next;
            pre = &(*pre)->next; //pre 总是保存当前节点的next指针的地址
        }
        
        ListNode* current = *pre;
        *pre= current->next;
        delete current;
        
        return head;
}