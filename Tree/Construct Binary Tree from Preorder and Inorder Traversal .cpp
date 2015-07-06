Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.




//方法 1 递归法

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
        if(preorder.size()==0)
            return nullptr;
        return make(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
}
    
template<typename Iter>
 TreeNode* make(Iter pFirst , Iter pLast , Iter iFirst , Iter iLast) 
{
         if(pFirst == pLast) return nullptr;
         if(iFirst == iLast) return nullptr;
         int val = *pFirst;
         
         TreeNode* node = new TreeNode(val);
         
         auto ival= find(iFirst,iLast,val);
         
         int leftLength = ival-iFirst;
         
         node->left = make(pFirst+1,pFirst+leftLength+1,iFirst,ival);
         node->right = make(pFirst+leftLength+1,pLast,ival+1,iLast);
         
         return node;
}



//迭代法

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
        if(preorder.size()==0)
            return NULL;

        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;

        f=i=j=0;

        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;

        while(i<preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[j])
            {
                t = st.top();
                st.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f==0)
                {
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }

        return root;
}