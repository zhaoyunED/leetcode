Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers 
from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.






//递归方法

ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;

        int val = head->val;
        ListNode* p = head->next;

        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }


// 双重指针
ListNode *deleteDuplicates(ListNode *head) {
        ListNode **runner = &head;

        if(!head || !head->next)return head;

        while(*runner)
        {
            if((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                ListNode *temp = *runner;
                while(temp && (*runner)->val == temp->val)
                    temp = temp->next;

                *runner = temp;
            }
            else
                runner = &((*runner)->next);
        }

        return head;
    }

//类似的方法
ListNode* deleteDuplicates(ListNode* head) {
        ListNode** curNext = &head;
        ListNode* cur =head;
        
        if(head == NULL || head->next ==NULL)
            return head;
        while(cur!=NULL)
        {
            ListNode* temp = cur;
            while(NULL != cur->next && cur->next->val == cur->val)
                cur = cur->next;
            if( cur == temp)
            {
                *curNext = temp;
                curNext = &(*curNext)->next;
            }
            cur = cur->next;
        }
        *curNext =NULL;
        return head;
    }