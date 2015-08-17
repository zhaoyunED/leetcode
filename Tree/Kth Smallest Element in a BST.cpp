Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).


//类似中序遍历 时间复杂度为O(k)
int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
             st.pop();
            if(--k == 0)
             return p->val;
             
            p = p->right;
            
        }
    }