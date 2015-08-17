Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can¡¯t invert a binary tree on a whiteboard so fuck off.


//just µÝ¹é
TreeNode* invertTree(TreeNode* root)
{        
        if(root)
        {
            TreeNode* newleft =NULL;
            TreeNode* newright =NULL;
            if(root->left) 
                newleft = invertTree(root->left);
            if(root->right)
                newright = invertTree(root->right);
            root->left = newright;
            root->right = newleft;
        }
        
        return root;
}

//·ÇµÝ¹é
TreeNode* invertTree(TreeNode* root)
{
        if (!root) return NULL;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            TreeNode* node = level.front();
            level.pop();
            swap(node -> left, node -> right);
            if (node -> left) level.push(node -> left);
            if (node -> right) level.push(node -> right);
        }
        return root; 
}