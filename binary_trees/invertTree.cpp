

    void solve(TreeNode* root){

        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL) return;

        TreeNode* temp = root->left;
        root->left=root->right;
        root->right = temp;

        solve(root->left);
        solve(root->right);
    }



    TreeNode* invertTree(TreeNode* root) {

        solve(root);
        return root;
        
    }

/*Given the root of a binary tree, invert the tree, and return its root.
Input: root = [2,1,3]
Output: [2,3,1]*/