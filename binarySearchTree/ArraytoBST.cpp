
class Solution {
  public:
  
    Node* construct(int l,int h,vector<int>& nums){
        
        if(l>h) return NULL;
        
        int mid = l + (h-l)/2;
        
        Node* root = new Node(nums[mid]);
        
        root->left = construct(l,mid-1,nums);
        root->right = construct(mid+1,h,nums);
        
        return root;
        
    }
  
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int l = 0;
        int h = nums.size()-1;
        return construct(l,h,nums);
        
    }
};



/*Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, */