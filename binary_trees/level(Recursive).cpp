class Solution {
public:

    void levelod(TreeNode* root,vector<vector<int>>& res,int level){

        if(root==NULL) return;

        if(res.size()<=level){
            res.push_back({});
        }

        res[level].push_back(root->val);
        levelod(root->left,res,level+1);
        levelod(root->right,res,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        levelod(root,res,0);
        return res;
        
    }
};