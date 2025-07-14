class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(flag){
                    ans[i] = node->val;
                }else{
                    ans[size-i-1] = node->val;
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                    
                }
                
            }
            res.push_back(ans);
            flag = !flag;
        }
        return res;
        
    }
};

/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[[4],[6,5],[10,8,9],[12,16,1,3],[7,14]]
*/