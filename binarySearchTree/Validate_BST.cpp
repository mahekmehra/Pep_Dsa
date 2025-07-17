bool solve(TreeNode* root,long long minVal, long long maxVal) {

        if(root==NULL) return true;
        if(root->val<=minVal || root->val>=maxVal){
            return false;
        }

        bool left = solve(root->left,minVal,root->val);
        bool right = solve(root->right,root->val,maxVal);

        return (left && right);
        
    }

    bool isValidBST(TreeNode* root){

        return solve(root,LLONG_MIN,LLONG_MAX);
    }

    /*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

//LLONG_MAX = maximum value of long var ()
//LLONG_MIN = minimum value of long var ()

*/
