TreeNode* searchBST(TreeNode* root, int val) {

        if(root==NULL) return NULL;

        if(root->val == val) return root;

        if(root->val>val){
            return searchBST(root->left,val);
        }else{
            return searchBST(root->right,val);
        }
    }


    //2nd approach (iterative)

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        while(temp!=NULL){
            if(temp->val==val){
                return temp;
            }else if(temp->val>val){
                temp = temp->left;
            }else{
                temp= temp->right;
            }
        }

        return NULL;
    }


    /*You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.*/