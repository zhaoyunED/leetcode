Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]



//同样的方法 同 1
// 递归 DFS

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
        vector<vector<int>> result;
        level(root,0,result);
        reverse(result.begin(),result.end()); // this 
        return result;
}
    
void level(TreeNode* root,int depth,vector<vector<int>> &result)
{
        if(root)
        {
            if(depth>= result.size())
            {
                vector<int> vect;
                
                result.push_back(vect);
            }
        
            result[depth].push_back(root->val);
            level(root->left,depth+1,result);
            level(root->right,depth+1,result);
        }
        
}

////BFS
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> list;
        queue<int> level; //存放每个节点所属的level
        
        list.push(root);
        level.push(0);
        
        
        while(!list.empty())
        {
            
            TreeNode* temp = list.front();
            list.pop();
            
            int qlevel = level.front();
            level.pop();
            
            if(qlevel >= result.size())
            {
                vector<int> ele;
                result.push_back(ele);
            }
            
            result[qlevel].push_back(temp->val);
            
            if(temp->left)
            {
                list.push(temp->left);
                level.push(qlevel+1);
            }
            
            if(temp->right)
            {
                list.push(temp->right);
                level.push(qlevel+1);
            }
        }
        
        reverse(result.begin(),result.end()); // this 
        return result;
}