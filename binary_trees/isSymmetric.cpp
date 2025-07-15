bool check(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;

        if(p->val!=q->val) return false;

        return (check(p->left,q->right) && check(p->right,q->left));
    }



    bool isSymmetric(TreeNode* root) {

        TreeNode* p = root->left;
        TreeNode* q = root->right;

        return (check(p,q));

        
    }


    /*Input: root = [1,2,2,3,4,4,3]
Output: true*/