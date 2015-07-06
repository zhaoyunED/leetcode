Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3


bool isSymmetric(TreeNode* root)
{
        if(root)
        {
            if(bSys(root->left,root->right))
                return true;
            else
                return false;
        }
        
        return true;
}
    
bool bSys(TreeNode* left,TreeNode* right){
        if(left && right)
        {
            if(left->val == right->val)
            {
                if(bSys(left->left,right->right) && bSys(left->right,right->left))
                    return true;
                else
                    return false;
            }else
                return false;
        }else if( left ==NULL && right ==NULL)
            return true;
        else return false;
}