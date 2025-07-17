int floor(Node* root, int x) {
        // Code here
        Node* temp = root;
        int ans = -1;
        while(temp!=NULL){
            if(temp->data==x){
                return temp->data;
            }else if(temp->data<x){
                ans = temp->data;
                temp= temp->right;
            }else{
                temp=temp->left;
            }
        }
    
        return ans;
    }

    ///2nd approach (recursive)

    void solve(Node* root, int input,int &ans){
    
        if(root==NULL) return;
    
        if(root->data==input){
            ans=root->data;
            return;
        }else if(root->data<input){
            ans=root->data;
            solve(root->right,input,ans);
        }else{
            solve(root->left,input,ans);
        }
    }
  
  
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        solve(root,input,ans);
        return ans;
    }

    /*You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.*/