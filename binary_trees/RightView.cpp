
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(i==size-1) ans.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
        }
        return ans;
    }

    //2nd approach

    void solve(vector<int> &res,Node *root,int level){
        
        if(root==NULL) return;
        
        if(level==res.size()){
            res.push_back(root->data);

        }
        
        solve(res,root->right,level+1);
        solve(res,root->left,level+1);
    }
  
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> res;
        solve(res,root,0);
        return res;
    }


    /*Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]*/