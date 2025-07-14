class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                ans.push_back(node->val);
            }
            res.push_back({ans});
        }
        return res;
        
    }
};


/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[[4],[5,6],[10,8,9],[3,1,16,12],[7,14]]
*/