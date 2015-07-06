Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?



//通过指针来记录 两个 调换的node
//1. Given a sequence {1, 4, 3, 7, 9}, you find pair 4(!<=)3, swap this pair and sequence is in order.
// 2. Given a sequence {1, 9, 4, 5, 3, 10}, you get first pair 9(!<=)4 and second pair 5(!<=)3, 
//swap pair 9(!<=)3 and sequence is in order.
// 3. Given a sequence, only in two above (general) cases, that you can just swap one pair numbers to convert 
//an unordered sequence into ordered. 
// 因此 one 指针 只被修改1次
// two 指针 可能 被修改两次 或者1次
void recoverTree(TreeNode* root) {
        if(root ==NULL)
            return;
        TreeNode *one =NULL;
        TreeNode *two =NULL;
        TreeNode p(numeric_limits<int>::min());
        TreeNode *pre =&p;
        
        recover(root,one,two,pre);
        
        if(one && two)
        {
            int temp = one->val;
            one->val = two->val;
            two->val = temp;
        }
    }
    
    void recover(TreeNode* root,TreeNode* &one,TreeNode* &two,TreeNode* &pre)
    {
        if(root)
        {
            recover(root->left,one,two,pre);
            
            if(root->val < pre->val)
            {
                if(one ==NULL)
                    one =pre;
                two = root;
            }
            pre = root;
            recover(root->right,one,two,pre);
        }
    }