Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3




vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n==0) 
        {
            result = getTree(1,0);
            return result;
        }
        result = getTree(1,n);
        
        return result;
    }
    
vector<TreeNode*> getTree(int from,int to)
    {
        vector<TreeNode*> result;
        if(from - to>0) 
            result.push_back(NULL);
        if(from -to == 0) 
            result.push_back(new TreeNode(from));
            
        if(from <to)
        {
            for(int i= from ;i<= to; i++)
            {
                vector<TreeNode*> left = getTree(from,i-1);
                vector<TreeNode*> right = getTree(i+1,to);
                
                for(int j=0 ;j<left.size();j++)
                for(int k=0 ;k<right.size() ;k++)
                {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left[j];
                    temp->right = right[k];
                    
                    result.push_back(temp);
                }
            }
        }
        
        return result;
}



//方法2 迭代的方法

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> tmp;
    vector<TreeNode *> ret;
    tmp.push_back(NULL);        
    ret.push_back(new TreeNode(1));
    if (!n) return tmp;

    /* insert the largeset number into previously contructed trees */
    for (int i = 2; i <= n; i++) {
        tmp.clear();
        for (int j = 0; j < ret.size(); j++) {
            /* firstly, put the largest number on the top of tree */
            TreeNode *orgTree = ret[j];                
            TreeNode *newNode = new TreeNode(i);
            newNode->left = copy(orgTree);
            tmp.push_back(newNode);

            /* traverse thru the right-most branch, 
             * insert the largest number one position after another */
            TreeNode *orgRunner = orgTree;
            while (orgRunner) {
                newNode = new TreeNode(i);
                newNode->left = orgRunner->right;
                orgRunner->right = newNode;
                tmp.push_back(copy(orgTree));

                /* recover the original tree */
                orgRunner->right = orgRunner->right->left;

                /* for the next loop */
                orgRunner = orgRunner->right;
            }
        }
        ret =  tmp;
    }
    return ret;
}

TreeNode *copy (TreeNode *root) {
    TreeNode *ret = NULL;
    if (root) {
        ret = new TreeNode(root->val);
        ret->left = copy(root->left);
        ret->right = copy(root->right);
    }
    return ret;
}