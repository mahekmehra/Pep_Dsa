void inorder(vector<int> &res,struct Node *root){
    
    if(root==NULL) return;
    
    inorder(res,root->left);
    res.push_back(root->data);
    inorder(res,root->right);
}



float findMedian(struct Node *root) {
    // Code here
    vector<int> res;
    inorder(res,root);
    int n = res.size();
    float ans = 0.0;
    if(n%2!=0){
        ans = res[n/2];
    }else{
        ans = (res[(n/2)-1] + res[n/2]);
        ans/=2;
    }
    
    return ans;
    
}

//if n = odd return (n/2)th index element
//if n = even return (((n/2-1)th index + (n/2)th index) element) / 2;