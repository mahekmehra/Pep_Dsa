class Solution {
  public:
  
    int countLeaves(Node* root) {
        // write code here
        if(root==NULL) return 0;
        
        int left = countLeaves(root->left);
        int right = countLeaves(root->right);
        
        if(left+right==0) return 1;
        else return (left+right);
    }
    
    int getSize(Node* node) {
        // code here
        if(node==NULL) return 0;
        
        int left = getSize(node->left);
        int right = getSize(node->right);
        
        return 1 + (left+right);
    }
    
    int height(Node* root){
        if(root==NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left,right);
    }
  
  
  
    bool isPerfect(Node *root) {
        // code here
        int leaves = countLeaves(root);
        int total = getSize(root);
        int h = height(root);
        h=h-1;
        
        return ((pow(2,h+1)-1)==total) && (pow(2,h)==leaves);
        
    }
};