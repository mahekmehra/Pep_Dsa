class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root==NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){

            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }  
        return ans;      
    }
};

/*Input
root =
[4,5,6,10,null,8,9,null,3,1,16,null,12,7,null,null,null,null,null,14]
Output
[4,5,10,3,7,6,8,1,16,9,12,14]
*/