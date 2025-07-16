//Leaf-Similar Trees

class Solution {
public:

    void leaf(TreeNode* root,vector<int> &res){

        if(root==NULL) return;

        if(!root->left && !root->right){
            res.push_back(root->val);
        }

        leaf(root->left,res);
        leaf(root->right,res);
    }




    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> ans1;
        vector<int> ans2;

        leaf(root1,ans1);
        leaf(root2,ans2);

        return(ans1==ans2);

       
        
    }
};

/*Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.*/