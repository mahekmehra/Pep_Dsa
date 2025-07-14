class Solution {
public:

    void preod(TreeNode* root,vector<int> &ans){

        if(root == NULL) return;

        ans.push_back(root->val);
        preod(root->left,ans);
        preod(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        preod(root,ans);
        return ans;
        
    }
};

/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[4,5,10,3,7,6,8,1,16,9,12,14]
*/