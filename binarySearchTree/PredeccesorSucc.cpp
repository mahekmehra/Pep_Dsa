

class Solution {
  public:
  
    void inorder(Node* root,vector<Node*> &ans){
        
        if(root==NULL) return;
        
        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
    }
  
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        inorder(root,ans);
        vector<Node*> res;
        Node* pre = NULL;
        Node* suc = NULL;
        
        int n = ans.size();
        int i=0,j=n-1;
        
        while(i<n){
            if(ans[i]->data<key){
                pre = ans[i];
            }
            i++;
        }
        
        while(j>=0){
            if(ans[j]->data>key){
                suc = ans[j];
            }
            j--;
        }
        
        res.push_back(pre);
        res.push_back(suc);
        return res;
    }
};

//2nd approach (iterative)
vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* temp = root;
        Node* pre = NULL;
        while(temp!=NULL){
            if(temp->data<key){
                pre = temp;
                temp=temp->right;
            }else{
                temp = temp->left;
            }
        }
        
        temp = root;
        Node* succ = NULL;
        while(temp!=NULL){
            if(temp->data>key){
                succ= temp;
                temp=temp->left;
            }else{
                temp = temp->right;
            }
        }
        
        return {pre,succ};
    }



/*You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. */