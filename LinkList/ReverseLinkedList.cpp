Reverse a singly linked list.

A linked list can be reversed either iteratively or recursively. Could you implement both?


//µİ¹é
ListNode* reverseList(ListNode* head)
{
        if(head == NULL || head->next ==NULL)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next =head;
        head->next =NULL;
       return newhead;
}


//µü´ú
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *pCurr = head;
    ListNode *pPrev = NULL;
    ListNode *pNext = NULL;

    while (pCurr != NULL)
    {
        pNext = pCurr->next;  //save next node
        pCurr->next = pPrev;
        if (pNext == NULL)
            head = pCurr;
        pPrev = pCurr;
        pCurr = pNext;
    }

    return head;
}


//¾«¼ò°æµü´ú
ListNode* reverseList(ListNode* head)
{
     ListNode* pre =NULL;
      while(head)
      {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
      }
      return pre;
}