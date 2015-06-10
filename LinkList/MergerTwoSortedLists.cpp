Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
{
        ListNode *helper=new ListNode(0);
        ListNode *head=helper;
        while(l1 && l2)
        {
             if(l1->val<l2->val) 
                helper->next=l1,l1=l1->next;
             else 
                helper->next=l2,l2=l2->next;
             helper=helper->next;
        }
        if(l1) helper->next=l1;
        if(l2) helper->next=l2;
        return head->next;
}