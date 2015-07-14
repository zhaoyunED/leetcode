Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
//一个指针走两步 一个指针走一步

bool hasCycle(ListNode *head)
{
        ListNode* pfast = head;  
        ListNode* pslow = head;  
        do{  
            if(pfast!=NULL)  
                pfast=pfast->next;  
            if(pfast!=NULL)  
                pfast=pfast->next;  
            if(pfast==NULL)  
                return false;  
            pslow = pslow->next;  
        }while(pfast != pslow);  
        return true;  
}




Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//画图即懂
ListNode *detectCycle(ListNode *head)
{
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
}