Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.




TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(left == NULL) return right;
        if(right==NULL) return left;
        
        return root;
    }