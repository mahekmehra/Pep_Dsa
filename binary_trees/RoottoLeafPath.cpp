
class Solution {
  public:
  
    void solve(Node *root,int &sum,int num){
        
        if(root==NULL) return;
        
        num = num*10 + root->data;
        if(!root->left && !root->right){
            sum += num;
            return;
        }
        
        solve(root->left,sum,num);
        solve(root->right,sum,num);
    }
  
  
  
    int treePathsSum(Node *root) {
        // code here.
        int sum = 0;
        solve(root,sum,0);
        return sum;
    }
};



/*Input:    
           1
          /
         2                    
Output: 12
Explanation: There is 1 leaf, resulting in leaf path of 12.*/