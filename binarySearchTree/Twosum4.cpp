//inorder approach

void inorder(TreeNode* root,vector<int> &res){

        if(root==NULL) return;

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
}

bool findTarget(TreeNode* root, int k) {

        vector<int> res;
        inorder(root,res);
        int n = res.size();

        int i=0, j=n-1;

        while(i<j){

            if(res[i]+res[j]==k) return true;
            else if(res[i]+res[j]<k) i++;
            else j--;
        }

        return false;
}

//recursive approach with map

bool solve(unordered_map<int,int> &mp,TreeNode* root, int k){

        if(root==NULL) return false;

        if(mp.find(k-root->val)!=mp.end()) return true;

        mp[root->val]++;

        return (solve(mp,root->left,k) || solve(mp,root->right,k));
}


bool findTarget(TreeNode* root, int k) {

        unordered_map<int,int>mp;
        return solve(mp,root,k);
}


/*Input: root = [5,3,6,2,4,null,7], k = 9
Output: true*/