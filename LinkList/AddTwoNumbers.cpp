
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


//
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	 if(l1 == NULL) return l2;
	 if(l2 == NULL) return l1;
     ListNode *preHead = new ListNode(0);
	 ListNode *p = preHead;
	 int extra=0;
	 while(l1 || l2 || extra )
	{
		int sum = (l1?l1->val:0)+(l2?l2->val:0);
		extra = sum /10;
		p->next = new ListNode(sum%10);
		p = p->next;
		l1 = l1?l1->next:l1;
		l2 = l2?l2->next:l2;
	}

	return preHead->next;
}
