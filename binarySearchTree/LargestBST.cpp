

bool isValidBST(Node *root,int mini,int maxi){
        
        if(root==NULL) return true;
        
        if(root->data<=mini || root->data>=maxi) return false;
        
        bool left = isValidBST(root->left,mini,root->data);
        bool right = isValidBST(root->right,root->data,maxi);
        
        return left && right;
}
    
int count(Node *root){
        
        if(root==NULL) return 0;
        
        return 1 + count(root->left) + count(root->right);
}
    
int largestBst(Node *root) {
        // Your code here
        
        if(isValidBST(root,INT_MIN,INT_MAX)==true){
            return count(root);
        }
        
        return max(largestBst(root->left),largestBst(root->right));
}


/*You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3*/