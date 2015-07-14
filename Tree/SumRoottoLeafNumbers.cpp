Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.


//DFS.....
int sumNumbers(TreeNode* root)
{
        int result =0;
        int cur=0;
        getNumbers(root,result,cur);
        
        return result;
}
    
void getNumbers(TreeNode* root,int& sum,int cursum)
{
        if(!root)
            return;
        cursum = cursum*10 + root->val;
        
        if(!root->left && !root->right)
        {
            sum += cursum;
        }
        
        if(root->left)
            getNumbers(root->left,sum,cursum);
        if(root->right)
            getNumbers(root->right,sum,cursum);
        
}