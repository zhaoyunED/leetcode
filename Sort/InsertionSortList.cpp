Sort a linked list using insertion sort.


ListNode *insertionSortList(ListNode *head)
{
        
       if (head == nullptr) return head;
        
        ListNode* curr = head -> next;
        head -> next = nullptr;
        
        while(curr != nullptr){
            ListNode* tmpHead = head;
            ListNode* prev = nullptr;
            ListNode* next = curr -> next;
            while(tmpHead != nullptr && tmpHead -> val <= curr -> val)
            {
                prev = tmpHead;
                tmpHead = tmpHead -> next;
            }
            
            if(prev != nullptr){
                //insert
                if(prev -> next){
                    curr -> next = prev -> next;
                    prev -> next = curr;
                }else
                {
                    prev -> next = curr;
                    curr -> next = nullptr;
                }
            }else{
                curr -> next = head;
                head = curr;
            }
            curr = next;
        }
        return head;
}