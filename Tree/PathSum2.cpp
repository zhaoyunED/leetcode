Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]


//典型的 DFS 求 全部路径的问题
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
        vector<vector<int>> result;
        vector<int> cur;
        getpathSum(result,sum,0,cur,root);
        return result;
}
    
void  getpathSum(vector<vector<int>>& result, int sum,int cursum,vector<int> cur,TreeNode* node)
{
        if(!node) return;
        
        cur.push_back(node->val);
        
        if(!node->left && !node->right && node->val+cursum == sum)
        {
            result.push_back(cur);
            return;
        }
        
        if(node->left)
            getpathSum(result,sum,cursum+node->val,cur,node->left);
        if(node->right)
            getpathSum(result,sum,cursum+node->val,cur,node->right);
}