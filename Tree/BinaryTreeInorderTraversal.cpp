Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?



//递归的方法
vector<int> inorderTraversal(TreeNode* root)
{
        vector<int> result;
        if(root == NULL)
            return result;
        
        inorder(root,result);
        return result;
}
    
    
void inorder(TreeNode *root,vector<int> &ret)
{
    if(root)
    {
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
}


//非递归的方法

vector<int> inorderTraversal(TreeNode* root)
{
        vector<int> result;
        stack<TreeNode*> sta;
        TreeNode* p =root;
        do
        {
            while(p != NULL)
            {
                sta.push(p);
                p = p->left;
            }
            
            if(!sta.empty())
            {
                p = sta.top();
                result.push_back(p->val);
                sta.pop();
                p = p->right;
            }
            
        }while(!sta.empty() || p!=NULL);
        
        return result;
}