
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


//�ݹ鷽ʽ

void preorder(TreeNode *root, vector<int> &result)
{
      if(root)
      {
            result.push_back(root->val);
            if(root->left) 
                preorder(root->left,result);//�ݹ�������
            if(root->right)
                preorder(root->right,result);//�ݹ�������
      }
}


vector<int> preorderTraversal(TreeNode *root)
{
        vector<int> result;
        preorder(root,result);
        return result;
}

//�ǵݹ鷽ʽ

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
            //����ջ����ȳ����ص��ȴ������������ٴ�����������ȷ��                                ��ÿ�ζ��ȷ��ʽڵ����������Ȼ����������
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);

        }

        return result;
}