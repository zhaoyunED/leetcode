Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.


bool isBalanced(TreeNode* root)
{
        if(!root)
            return true;
        bool isbalance =true;
        isBan(root,isbalance);
        
        return isbalance;
}
    
int isBan(TreeNode* root, bool& isbalance)
{
    if(root == NULL) return 0;
    if(!isbalance) return 0;
        
    int leftDepth = isBan(root->left,isbalance);
    int rightDepth = isBan(root->right,isbalance);
        
    if(!isbalance) return 0;
        
    isbalance = abs(leftDepth-rightDepth) <= 1;
    return max(leftDepth, rightDepth) + 1;
        
}