/*Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.*/

 bool solve(TreeNode* root,int sum,int targetSum){

        if(root==NULL) return false;

        sum+=root->val;

        if(root->left == NULL && root->right==NULL){
            return sum==targetSum;
        }

        
        return solve(root->left,sum,targetSum) || solve(root->right,sum,targetSum);
    }



    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        return solve(root,sum,targetSum);
        
    }

    /*Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.*/