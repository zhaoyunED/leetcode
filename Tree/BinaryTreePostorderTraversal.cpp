Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?



//·ÇµÝ¹é

vector<int> postorderTraversal(TreeNode *root)
{
        vector<int> result;
        if(!root) return result;

        stack<TreeNode*> stack;
        stack.push(root);

        while(!stack.empty())
        {
            TreeNode* node = stack.top();
            result.push_back(node->val);
            stack.pop();

            if(node->left) stack.push(node->left);
            if(node->right) stack.push(node->right);
        }
        reverse(result.begin(), result.end());

        return result;
}

//µÝ¹é

void postorder(TreeNode *root,vector<int> &result)
{
        if(root)
        {
            postorder(root->left,result);
            postorder(root->right,result);
            result.push_back(root->val);
        }
}

vector<int> postorderTraversal(TreeNode *root)
{
        vector<int> result;
        postorder(root,result);
        return result;
}