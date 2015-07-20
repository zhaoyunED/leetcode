Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].


class Solution {

int level = 0;//number of numbers that have been "seen".
    vector<int> answer;
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root!=NULL) travDown(root,0);
        return answer;
    }
    void travDown(TreeNode* nd, int N){//travel down, always go right first
        if (N>=level) {
            answer.push_back(nd->val);
            level++;
        }
        ++N;
        if (nd->right!=NULL) travDown(nd->right,N);
        if (nd->left!=NULL) travDown(nd->left,N);
    }
    
};