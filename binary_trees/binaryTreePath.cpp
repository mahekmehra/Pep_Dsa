class Solution {
public:

    void solve(vector<string> &res,string ans,TreeNode* root){

        if(root==NULL) return;

        ans+=to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            res.push_back(ans);
        }

        solve(res,ans+"->",root->left);
        solve(res,ans+"->",root->right);
        ans.pop_back();

    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string ans="";
        solve(res,ans,root);
        return res;
    }
};

/*Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]*/