Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.



//保存第n,m个节点,第m节点的前一个节点，第n个节点的后一个节点
ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next ==NULL || m>=n)
            return head;
        ListNode* mPre=NULL;
        ListNode* nNext=NULL;
        
         ListNode* curr=head;
         ListNode* next=NULL;
         ListNode* pre=NULL;
         ListNode *mTh= NULL;
         ListNode *nTh= NULL;
        for(int i=1;i<=n;i++)
        {
            next =curr->next;
            
            if(i==m)
            {
                mTh = curr;
                mPre = pre;
            }
            
            if(i == n)
            {
                   nTh = curr;
                   nNext = next;
                   curr->next = pre;
             }
            if(i>m && i<n)
            {
                curr->next = pre;//
            }
            
            pre = curr;
            curr =next;
        }
        if(m==1)
        {
            mTh->next = nNext;
            head = nTh;
        }else{
            mPre->next = nTh;
            mTh->next = nNext;
        }
        
        return head;
    }