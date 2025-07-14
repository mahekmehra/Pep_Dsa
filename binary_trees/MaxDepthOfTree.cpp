class Solution {
public:
    int maxDepth(TreeNode* root) {

        queue<TreeNode*> q;
        if(root==NULL) return 0;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
            count++;
        }
        return count;
        
    }
};

//2nd approach

class Solution {
public:
    int maxDepth(TreeNode* root) {

        TreeNode* temp = root;

        if(root==NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left,right);
        
    }
};