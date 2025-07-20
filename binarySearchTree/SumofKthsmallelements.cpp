void find(Node* root,int &k,int &ans){
    
    if(root==NULL) return;
    
    find(root->left,k,ans);
    k--;
    if(k==0){
        ans = root->data;
        return;
    }
    
    find(root->right,k,ans);
}

void solve(Node* root,int ans,int &sum){
    
    if(root==NULL) return;
    
    solve(root->left,ans,sum);
    
    if(root->data<=ans){
        sum+=root->data;
    }
    solve(root->right,ans,sum);
}



int sum(Node* root, int k) {

    // Your code here
    int ans = -1;
    find(root,k,ans);
    int sum = 0;
    solve(root,ans,sum);
    return sum;
    
    
}

//2nd approach (shorter one)

void solve(Node* root,int &k,int &sum){
    
    if(root==NULL) return;
    
    solve(root->left,k,sum);
    
    if(k>0){
        sum+=root->data;
        k--;
    }
    solve(root->right,k,sum);
}



int sum(Node* root, int k) {

    // Your code here
    int sum = 0;
    solve(root,k,sum);
    return sum;
    
    
}





/* Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

Example 1:

Input: 
          20
        /    \
       8     22
     /    \
    4     12
         /    \
        10    14   , K=3

Output: 22
Explanation:
Sum of 3 smallest elements are: 
4 + 8 + 10 = 22*/