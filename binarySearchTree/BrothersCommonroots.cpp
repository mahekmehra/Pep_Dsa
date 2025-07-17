//Brothers From Different Roots

class Solution {
  public:
  
    void inorder(Node* root,vector<int> &ans){
        
        if(root==NULL) return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
  
  
    int countPairs(Node* root1, Node* root2, int x) {
        
        vector<int> arr1;
        vector<int> arr2;
        
        inorder(root1,arr1);
        inorder(root2,arr2);
    
        
        int m = arr1.size();
        int n = arr2.size();
        
        int i = 0, j=n-1;
        
        int count = 0;
        
        while(i<m && j>=0){
            if(arr1[i]+arr2[j]==x){
                count++;
                i++;
                j--;
                
            }else if(arr1[i]+arr2[j]>x){
                j--;
            }else{
                i++;
            }
        }
        
        return count;
    }
};


/*Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)*/