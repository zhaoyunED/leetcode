Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

int maxPathSum(TreeNode* root)
{
        int maxPath = INT_MIN;
        dfsMaxPath(root, maxPath);
        return maxPath;
}

//����Ĵ���ֵ��ѧϰ
int dfsMaxPath(TreeNode *root, int &maxPath)
{
        if (!root) return 0;
        int l = max(0, dfsMaxPath(root->left, maxPath));
        int r = max(0, dfsMaxPath(root->right, maxPath));
        maxPath = max(maxPath, l + r + root->val);
        return root->val + max(l, r);
}