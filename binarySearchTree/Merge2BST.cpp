void inorder(Node *root,vector<int> &res){
        
        if(root==NULL) return;
        
        inorder(root->left,res);
        res.push_back(root->data);
        inorder(root->right,res);
}
    
    
    
  
vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> res1;
        vector<int> res2;
        inorder(root1,res1);
        inorder(root2,res2);
        
        int n = res1.size();
        int m = res2.size();
        
        vector<int>ans(n+m);
        
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(res1[i]<=res2[j]){
                ans[k++]=res1[i++];
            }else{
                ans[k++]=res2[j++];
            }
        }
        
        while(i<n){
            ans[k++]=res1[i++];
        }
        
        while(j<m){
            ans[k++]=res2[j++];
        }
        
        return ans;
}


/*Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input: root1 = [5, 3, 6, 2, 4]
 
root2 = [2, 1, 3, N, N, N, 7, 6]
 
Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].*/