
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?


//递归方式

void preorder(TreeNode *root, vector<int> &result)
{
      if(root)
      {
            result.push_back(root->val);
            if(root->left) 
                preorder(root->left,result);//递归左子树
            if(root->right)
                preorder(root->right,result);//递归右子树
      }
}


vector<int> preorderTraversal(TreeNode *root)
{
        vector<int> result;
        preorder(root,result);
        return result;
}

//非递归方式

vector<int> preorderTraversal(TreeNode *root)
{
        vector<int> result; 
        if(!root) return result;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* n = s.top(); 
            result.push_back(n->val);
            s.pop();
            //根据栈后进先出的特点先存入右子树，再存入左子树，确保                                了每次都先访问节点的左子树，然后是右子树
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);

        }

        return result;
}