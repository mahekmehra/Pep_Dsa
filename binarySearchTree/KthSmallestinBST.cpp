
//recursive approach

void solve(TreeNode* root,int &ans,int &k){

        if(root==NULL) return;

        solve(root->left,ans,k);

        k--;
        if(k==0){
            ans = root->val;
            return;
        }

        solve(root->right,ans,k);


}

int kthSmallest(TreeNode* root, int k) {

        int ans = 0;
        solve(root,ans,k);
        return ans;
        
}

//inorder approach

void inorder(TreeNode* root,vector<int> &res){

        if(root==NULL) return;

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
}

int kthSmallest(TreeNode* root, int k) {

        vector<int> res;
        inorder(root,res);
        k=k-1;
        return res[k];
        
}

/*Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.*/