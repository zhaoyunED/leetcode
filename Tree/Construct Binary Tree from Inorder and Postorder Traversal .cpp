Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
        return make(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
    
    template<typename Iter>
    TreeNode* make(Iter ibegin,Iter iend,Iter pobegin,Iter poend)
    {
        if(ibegin == iend) return nullptr;
        if(pobegin == poend) return nullptr;
        
        int val = *(poend-1);
        TreeNode* node = new TreeNode(val);
        
        auto  idx= find(ibegin,iend,val);
        int leftLength = idx-ibegin;
        
        node->left = make(ibegin,idx+1,pobegin,pobegin+leftLength);
        node->right =make(idx+1,iend,pobegin+leftLength,poend-1);
        
        return node;
    }


//µü´ú·¨

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 

        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
}