    void solve(TreeNode* root,int &ans,int level){

        if(root==NULL) return;

        if(!root->left && !root->right){
            ans = min(ans,level);
        }

        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);


    }


    int minDepth(TreeNode* root) {

        if(root==NULL) return 0;


        int ans = INT_MAX;
        solve(root,ans,1);
        return ans;
    }
};