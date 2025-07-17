int findCeil(Node* root, int input) {
    // Your code here
    Node* temp = root;
    int ans = -1;
    while(temp!=NULL){
        if(temp->data==input){
            return temp->data;
        }else if(temp->data>input){
            ans = temp->data;
            temp= temp->left;
        }else{
            temp=temp->right;
        }
    }
    
    return ans;
}

//2nd approach (recursive)
void solve(Node* root, int input,int &ans){
    
    if(root==NULL) return;
    
    if(root->data==input){
        ans=root->data;
        return;
    }else if(root->data>input){
        ans=root->data;
        solve(root->left,input,ans);
    }else{
        solve(root->right,input,ans);
    }
}


int findCeil(Node* root, int input) {
    // Your code here
    int ans = -1;
    solve(root,input,ans);
    return ans;
}



/*Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Examples:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], X = 3

Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.*/