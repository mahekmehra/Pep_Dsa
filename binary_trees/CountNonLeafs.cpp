class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        if(root==NULL) return 0;
        
        if(root->left==NULL && root->right == NULL) return 0;
        
        int left = countNonLeafNodes(root->left);
        int right = countNonLeafNodes(root->right);
        
        return 1 + (left+right);
    }
};