
int check(Node *root){
        
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int left = check(root->left);
        int right = check(root->right);
        
        if(left==-1 || right==-1) return -1;
        if(left+right == root->data) return root->data;
        else return -1;
        
       
    }
    
    
    int isSumProperty(Node *root) {
        // Add your code here
        int val = check(root);
        if(val!=-1) return 1;
        else return 0;
        
    }


/*Input:
Binary tree
       35
      /  \
     20   15
    / \   / \
   15  5 10  5

Output: 1
Explanation: 
Here, every node is sum of its left and right child.*/