
class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    
    void inorder(Node* root,vector<int> &ans){
        
        if(root==NULL) return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int> arr1;
        vector<int> arr2;
        inorder(r1,arr1);
        inorder(r2,arr2);
        
        vector<int> res;
        
        int i=0,j=0;
        int n = arr1.size();
        int m = arr2.size();
        
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                res.push_back(arr1[i]);
                i++;
                j++;
            }else if(arr1[i]<arr2[j]){
                i++;
            }else{
                j++;
            }
        }
        
        return res;
    }
};



/*Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9

Output: 4 7 9 10*/