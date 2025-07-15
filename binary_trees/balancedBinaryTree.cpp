    int count(TreeNode* root){
        if(root==NULL) return 0;

        int left = count(root->left);
        int right = count(root->right);

        return 1 + max(left,right);
    }


    bool isBalanced(TreeNode* root) {

        if (root==NULL) return true;

        int left = count(root->left);
        int right = count(root->right);

        if(abs(left-right)>1) return false;

        return (isBalanced(root->right) && isBalanced(root->left));
         
    }



    /*Input: root = [3,9,20,null,null,15,7]
Output: true*/