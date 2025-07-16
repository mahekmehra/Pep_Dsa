class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                
                if(i==0) ans.push_back(temp->data);
                
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
        
        solve(res,root->left,level+1);
        solve(res,root->right,level+1);
    }
  
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> res;
        solve(res,root,0);
        return res;
    }
};

/*You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.*/