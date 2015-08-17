Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.



//先算两边的树的深度若一样 直接返回
//之后分治
int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftDepth = 0, rightDepth= 0;
        for(TreeNode* p=root; p; p=p->left) ++leftDepth;
        for(TreeNode* p=root; p; p=p->right) ++rightDepth;
        if (leftDepth==rightDepth) {
            return (1<< leftDepth) - 1 ;
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1 ;
        }
    }


