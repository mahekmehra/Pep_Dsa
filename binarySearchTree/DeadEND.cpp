
//recursive approach

bool solve(Node *root,int MIN,int MAX){
        
        if(root==NULL) return false;
        
        if(root->data==MIN && root->data==MAX) return true;
        
        return solve(root->left,MIN,root->data-1) || solve(root->right,root->data+1,MAX);
}
  
  
bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,1,1e8);
}

//inorder approach

vector<int> leaf;
    
    void inorder(Node *root,vector<int> &arr){
        
        if(root==NULL) return;
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->data);
        }
        
        inorder(root->right,arr);
    }
  
  
  
  
    bool isDeadEnd(Node *root) {
        // Code here
        vector<int> arr = {0};
        inorder(root,arr);
        
        int n = arr.size();
        int m = leaf.size();
        
        int i=1,j=0;
        
        while(i<n && j<m){
            
            if(arr[i]==leaf[j]){
                if(arr[i-1]==leaf[j]-1 && arr[i+1]==leaf[j]+1){
                    return true;
                }
                j++;
            }
            i++;
        }
        return false;
        
    }

/*You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.*/