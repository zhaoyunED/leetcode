Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.




//方法1

class Solution {
    bool first = true;
    int prev = 0;
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;

        return (
            isValidBST(root->left)
            && check(root->val)
            && isValidBST(root->right));
    }

    bool check(int val)
    {
        if(first)
        {
            first = false;
            prev = val;
            return true;
        }

        if(prev >= val) return false;

        prev = val;
        return true;
    }
};


//方法2 和方法1基本一样// 用一个变量来保存 prev 
bool isValidBST(TreeNode* root)
{
        TreeNode* prev =NULL;
        return validate(root,prev);
}
    
bool validate(TreeNode* node, TreeNode* &prev) 
{
        if(node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
}


//方法3
bool isValidBST(TreeNode *root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

// decide if tree is a BST within range (lower, upper), exclusive
bool isValidBSTHelper(TreeNode *root, long lower, long upper)
{
    if (!root)  return true;

    long val = (long)root->val;
    return (val > lower && val < upper && isValidBSTHelper(root->left, lower, val) && isValidBSTHelper(root->right, val, upper));
}