Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

//花式层次遍历
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
       vector<vector<int>> result;
       if(!root) return result;
       
       queue<TreeNode*> list;
       list.push(root);
       
       bool left = true;
       
       vector<int> cur;
       
       while(!list.empty())
       {
           int count = list.size();
           
           for(int i=0;i <count ;i++)
           {
               TreeNode* temp = list.front();
               list.pop();
               cur.push_back(temp->val);
               if(temp->left)
                  list.push(temp->left);
               if(temp->right)
                  list.push(temp->right);
           }
           
           if(!left)
           {
               reverse(cur.begin(), cur.end());
               left =true;
           }else
               left =false;
           result.push_back(cur);
           cur.clear();
       }
       
       return result;
}