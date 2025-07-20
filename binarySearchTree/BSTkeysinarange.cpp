
void solve(vector<int> &res,Node *root,int low, int high){
        
        if(root==NULL) return;
        
        
        solve(res,root->left,low,high);
        
        if(root->data>=low && root->data<=high){
            res.push_back(root->data);
        }
        
        
        solve(res,root->right,low,high);
}
  
  
  
vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int> res;
        solve(res,root,low,high);
        return res;
}




/*Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

Example 1:

Input:
       17
     /    \
    4     18
  /   \
 2     9 
l = 4, h = 24
Output: 
4 9 17 18 */