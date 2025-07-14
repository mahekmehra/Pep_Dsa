class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root==NULL) return 0;
        
        int left = countLeaves(root->left);
        int right = countLeaves(root->right);
        
        if(left+right==0) return 1;
        else return (left+right);
    }
};

