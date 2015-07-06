Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.





//ÕÒÖĞ¼ä½Úµã
TreeNode* sortedListToBST(ListNode* head)
{
         return sortedListToBST( head, NULL );
}
    
TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
{
        if( head == tail )
            return NULL;
        if( head->next == tail )    // 
        {   
            TreeNode *root = new TreeNode( head->val );
            return root;
        }
        ListNode *mid = head, *temp = head;
        while( temp != tail && temp->next != tail )    // Ñ°ÕÒÖĞ¼ä½Úµã
        {
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode *root = new TreeNode( mid->val );
        root->left = sortedListToBST( head, mid );
        root->right = sortedListToBST( mid->next, tail );
        return root;
}


//·½·¨2  ÀûÓÃÖĞĞò±éÀúµÄË¼Â·
//run time complexity is still O(N).
ListNode *list;
int count(ListNode *node){
        int size = 0;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
}

TreeNode *generate(int n)
{
        if (n == 0)
            return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = generate(n / 2);
        node->val = list->val;
        list = list->next;
        node->right = generate(n - n / 2 - 1);
        return node;
}

TreeNode *sortedListToBST(ListNode *head)
{
        this->list = head;
        return generate(count(head));
}