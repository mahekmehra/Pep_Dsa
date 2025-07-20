
//recursive approach


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL) return NULL;

        int curr = root->val;
        if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }        
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;
}

//iterative approach

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root!=NULL){
            if(root->val<p->val && root->val<q->val){
                root=root->right;
            }else if(root->val>p->val && root->val>q->val){
                root=root->left;
            }else{
                return root;
            }
        }
        return NULL;
}

/*Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.*/