Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.





bool isSameTree(TreeNode* p, TreeNode* q)
{
        if(p == NULL && q== NULL)
            return true;
        if(p == NULL || q== NULL)
            return false;
        if(p->val != q->val)
            return false;
        if( isSameTree(p->left,q->left) && isSameTree(p->right,q->right) )
            return true;
        else
            return false;
}