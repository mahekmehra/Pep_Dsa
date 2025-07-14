class Solution {
  public:
    int getSize(Node* node) {
        // code here
        if(node==NULL) return 0;
        
        int left = getSize(node->left);
        int right = getSize(node->right);
        
        return 1 + (left+right);
    }
};