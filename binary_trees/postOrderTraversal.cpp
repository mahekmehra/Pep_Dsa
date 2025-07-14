class Solution {
public:

    void post(TreeNode* root,vector<int> &ans){
        
        if(root==NULL) return;

        post(root->left,ans);
        post(root->right,ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        post(root,ans);
        return ans;
        
    }
};

/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[7,3,10,5,1,16,8,14,12,9,6,4]*/