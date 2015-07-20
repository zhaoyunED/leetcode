Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

//如同中序遍历

public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = s.top();
        s.pop();
        pushLeft(top->right);
        return top->val;
    }
    
    void pushLeft(TreeNode* root)
    {
        if(root != NULL)
        {
            s.push(root);
            TreeNode* cur = root;
            while(cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
            }
        }
    }