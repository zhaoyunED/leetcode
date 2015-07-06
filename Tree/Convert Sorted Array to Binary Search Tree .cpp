

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.












TreeNode *sortedArrayToBST(vector<int> &num) {
        return BuildTree(num,0,num.size()-1);
    }
    
    TreeNode *BuildTree(vector<int> &num, int start, int end)
    {
        if(start > end) return NULL;
        if(start == end) return new TreeNode(num[start]);
        int mid = (start+end)/2;
        TreeNode *treenode = new TreeNode(num[mid]);
        treenode->left = BuildTree(num,start,mid-1);
        treenode->right = BuildTree(num,mid+1,end);
        return treenode;
    }