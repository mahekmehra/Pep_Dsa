class Solution {
public:

    void tree(TreeNode* root,vector<int> &ans){

        if(root==NULL){
            return;
        }

        tree(root->left,ans);
        ans.push_back(root->val);
        tree(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        tree(root,ans);
        return ans;
        
    }
};

/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[10,7,3,5,4,1,8,16,6,9,14,12]
*/